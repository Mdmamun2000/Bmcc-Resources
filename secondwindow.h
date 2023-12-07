#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "resources.h"
#include"mentorship.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_resources_clicked();

    void on_pushButton_Mentorship_clicked();

    void on_pushButton_backtomain_clicked();

private:
    Ui::SecondWindow *ui;
    resources  *Resources;
    mentorship *Mentorship;
};

#endif // SECONDWINDOW_H
