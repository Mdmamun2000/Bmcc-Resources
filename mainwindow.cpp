#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/rrsources/img/Bmccfrontpage.jpg");
    int w = ui->label_image1->width();
     int h = ui->label_image1->height();
    ui->label_image1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

     QPixmap pix2(":/rrsources/img/4900299.jpeg");
     int w1 = ui->label_background->width();
     int h1 = ui->label_background->height();
     ui->label_background->setPixmap(pix2.scaled(w1,h1,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    // SecondWindow secWindow;
    // secWindow.setModal(true);
    // secWindow.exec();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if (username == "Bmcc" && password == "csc211h"){
       // QMessageBox::information(this,"Login","username and password is correct");
        ui->statusbar->showMessage("username and password is correct",5000);
        //hide();
        secondWindow = new SecondWindow(this);
        secondWindow->show();
    }else {
        //QMessageBox::warning(this,"Login","username and password is incorrect");
         ui->statusbar->showMessage("username and password is incorrect",5000);
    }

}

