#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QPixmap>

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/rrsources/img/alMut5u.jpg");
    int w = ui->label_secondbackground->width();
    int h = ui->label_secondbackground->height();
    ui->label_secondbackground->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix2(":/rrsources/img/javier-trueba-iQPr1XkF5F0-unsplash.jpg");
    int w2 = ui->label_SecImg1->width();
    int h2 = ui->label_SecImg1->height();
    ui->label_SecImg1->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
}


SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_resources_clicked()
{
    //hide();
    Resources = new resources(this);
    Resources->show();
}


void SecondWindow::on_pushButton_Mentorship_clicked()
{
    //hide();
    Mentorship = new mentorship(this);
    Mentorship->show();
}


void SecondWindow::on_pushButton_backtomain_clicked()
{
    reject();
}

