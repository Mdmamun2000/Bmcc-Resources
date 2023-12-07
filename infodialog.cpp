// infodialog.cpp
#include "infodialog.h"
#include "ui_infodialog.h"
#include <QPixmap>

template <typename T>
InfoDialog<T>::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/rrsources/img/lukas-blazek-EWDvHNNfUmQ-unsplash.jpg");
    int w = ui->label_backgroundInfo->width();
    int h = ui->label_backgroundInfo->height();
    ui->label_backgroundInfo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

template <typename T>
InfoDialog<T>::~InfoDialog()
{
    delete ui;
}

template <typename T>
void InfoDialog<T>::setData(const T &data)
{
    // Set data in the dialog UI (customize as needed)
    ui->label_info->setText(data);
}
// Explicit instantiation for QString
template class InfoDialog<QString>;
