// scholarshipinfo.cpp
#include "scholarshipinfo.h"
#include "ui_scholarshipinfo.h"
#include <QComboBox>

ScholarshipInfo::ScholarshipInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScholarshipInfo)
{
    ui->setupUi(this);
    QPixmap pix(":/rrsources/img/joanna-kosinska-PbgY3ptgA4A-unsplash.jpg");
    int w = ui->label_imgSI->width();
    int h = ui->label_imgSI->height();
    ui->label_imgSI->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}


ScholarshipInfo::~ScholarshipInfo()
{
    delete ui;
}

void ScholarshipInfo::setScholarshipData(const QString &name, const QString &amount, const QString &deadline)
{
    ui->comboBox_scholarshipType->clear();
    ui->comboBox_scholarshipType->addItem(name);
    // Add more scholarships as needed
    // ...

    // Display scholarship information
    QString scholarshipInfo = "Name: " + name + "\n"
                              + "Amount: " + amount + "\n"
                              + "Deadline: " + deadline;

    ui->plainTextEdit_scholarInfo->setPlainText(scholarshipInfo);
}
