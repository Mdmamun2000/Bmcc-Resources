#include "mentorship.h"
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <ctime>  // Include for std::time function

mentorship::mentorship(QWidget *parent)
    : QDialog(parent), ui(new Ui::mentorship)
{
    ui->setupUi(this);
    createStudents();
    std::srand(std::time(0));  // Seed the random number generator
}

mentorship::~mentorship()
{
    delete ui;
}

void mentorship::createStudents()
{
    // Read students from a file (assuming the file contains names of freshmen)
    QFile file("/Users/fsadid/BmccApp");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString studentName = in.readLine();
            freshmen.append(Freshman(studentName));
        }
        file.close();
    }

    // Create five Senior objects
    seniors.append(Senior("John Doe"));
    seniors.append(Senior("Jane Smith"));
    seniors.append(Senior("Bob Johnson"));
    seniors.append(Senior("Alice Johnson"));
    seniors.append(Senior("Jose Vergas"));
}

Senior mentorship::getRandomSenior()
{
    int randomIndex = rand() % seniors.size();
    return seniors[randomIndex];
}

void mentorship::on_pushButton_Peerconnect_clicked()
{
    // Get the freshman's name from user input
    QString freshmanName = QInputDialog::getText(this, "Enter Freshman's Name", "Freshman's Name:");

    // Input validation: Ensure the name is not empty
    if (freshmanName.isEmpty()) {
        QMessageBox::critical(this, "Error", "Freshman's name cannot be empty.");
        return;
    }

    // Check if the freshman already exists
    for (const auto& freshman : freshmen) {
        if (freshman.getName() == freshmanName) {
            QMessageBox::critical(this, "Error", "Freshman with this name already exists.");
            return;
        }
    }

    // Create the Freshman
    Freshman newFreshman(freshmanName);
    freshmen.append(newFreshman);

    // Connect Freshman with a random Senior
    Senior selectedSenior = getRandomSenior();
    newFreshman.connectWithSenior(selectedSenior);

    hide();
    Peer = new peer(this);

    // Display the connection information in the peer class
    QString connectionInfo =  newFreshman.getName() +" You are Connected with " + selectedSenior.getName();
    Peer->showConnectionInfo(connectionInfo);
    Peer->setParent(this);

    Peer->show();
}

void mentorship::on_pushButton_Mback_clicked()
{
    reject();
}

