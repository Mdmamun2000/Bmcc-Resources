#include "resources.h"
#include "ui_resources.h"
#include "scholarshipinfo.h"
#include "infodialog.h"



#include <QFile>
#include <QTextStream>
#include <QMessageBox>

resources::resources(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resources)
{
    ui->setupUi(this);
    QPixmap pix2(":/rrsources/img/Screenshot 2023-12-04 at 5.51.13 PM.png");
    int w2 = ui->label_Rbackground->width();
    int h2 = ui->label_Rbackground->height();
    ui->label_Rbackground->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));

    // Populate the scholarship array with some data
    scholarships[0][0] = "Merit Scholarship";
    scholarships[0][1] = "1000 USD";
    scholarships[0][2] = "January 15, 2024";

    scholarships[1][0] = "Need-Based Scholarship";
    scholarships[1][1] = "500 USD";
    scholarships[1][2] = "February 28, 2024";

    scholarships[2][0] = "STEM Scholarship";
    scholarships[2][1] = "1500 USD";
    scholarships[2][2] = "March 31, 2024";

    // Add scholarship names to the QComboBox
    ui->comboBox_scholarshipType->addItem("Merit Scholarship");
    ui->comboBox_scholarshipType->addItem("Need-Based Scholarship");
    ui->comboBox_scholarshipType->addItem("STEM Scholarship");




}

resources::~resources()
{
    delete ui;
}



void resources::on_pushButton_Scholarship_clicked()
{
    int selectedScholarshipIndex = ui->comboBox_scholarshipType->currentIndex();

    if (selectedScholarshipIndex >= 0 && selectedScholarshipIndex < 3) {
        QString scholarshipName = scholarships[selectedScholarshipIndex][0];
        QString scholarshipAmount = scholarships[selectedScholarshipIndex][1];
        QString scholarshipDeadline = scholarships[selectedScholarshipIndex][2];

        // Open ScholarshipInfo dialog and set scholarship data
        ScholarshipInfo scholarshipInfoDialog;
        scholarshipInfoDialog.setScholarshipData(scholarshipName, scholarshipAmount, scholarshipDeadline);
        scholarshipInfoDialog.exec();
    } else {
        QMessageBox::information(this, "Error", "Invalid scholarship selection.");
    }


}

void resources::on_pushButton_backtos_clicked()
{
    reject();
}




void resources::on_pushButton_Programs_clicked()
{
    QString allProgramsInfo;

    // Example program data (replace with your actual program data)
    QString programName1 = "Computer Science";
    QString programDescription1 = "A program in computer science that covers various topics.";

    QString programName2 = "Math Club";
    QString programDescription2 = "A club for math enthusiasts.";

    // Concatenate information for all programs
    allProgramsInfo += programName1 + "\n" + programDescription1 + "\n\n";
    allProgramsInfo += programName2 + "\n" + programDescription2 + "\n\n";

    // Open InfoDialog and set program data
    InfoDialog<QString> allProgramsDialog;
    allProgramsDialog.setData(allProgramsInfo);
    allProgramsDialog.exec();

    /* // Example program data (replace with your actual program data)
    QString programName = "Computer Science";
    QString programDescription = "A program in computer science that covers various topics.";


    // Open InfoDialog and set program data
    InfoDialog<QString> programInfoDialog;
    programInfoDialog.setData(programName + "\n" + programDescription);
    programInfoDialog.exec();*/
}

