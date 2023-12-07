#include "peer.h"
#include "ui_peer.h"
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPixmap>

peer::peer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::peer)
{
    ui->setupUi(this);
    QPixmap pix(":/rrsources/img/lukas-blazek-EWDvHNNfUmQ-unsplash.jpg");
    int w = ui->label_pbackground->width();
    int h = ui->label_pbackground->height();
    ui->label_pbackground->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

peer::~peer()
{
    delete ui;
}
void peer::showConnectionInfo(const QString& info) {
    ui->label_showmsg->setText(info);

    // Ask the user to input a question
    QInputDialog inputDialog(this);
    inputDialog.setWindowTitle("Ask a Question");
    inputDialog.setLabelText("Please enter your question:");

    // Set the size of the input dialog (adjust these values accordingly)
    inputDialog.setMinimumWidth(951);
    inputDialog.setMinimumHeight(791);

    // Retrieve the user's input
    if (inputDialog.exec() == QDialog::Accepted) {
        QString question = inputDialog.textValue();

    // Save the question to a text file
    saveQuestionToFile(question);
}
}

void peer::saveQuestionToFile(const QString& question) {
    // Open a text file for appending
    QFile file("/Users/fsadid/BmccApp/user_questions.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << question << "\n";
        file.close();
        QMessageBox::information(this, "Question Saved", "Your question has been saved.");
    } else {
        QMessageBox::warning(this, "Error", "Unable to save the question to the file.");
    }
}

void peer::on_pushButton_Pback_clicked()
{
    reject();
}

