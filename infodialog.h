// infodialog.h
#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

template <typename T>
class InfoDialog : public QDialog
{
public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    void setData(const T &data);

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
