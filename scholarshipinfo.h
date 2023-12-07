// scholarshipinfo.h
#ifndef SCHOLARSHIPINFO_H
#define SCHOLARSHIPINFO_H

#include <QDialog>

namespace Ui {
class ScholarshipInfo;
}

class ScholarshipInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ScholarshipInfo(QWidget *parent = nullptr);
    ~ScholarshipInfo();

    void setScholarshipData(const QString &name, const QString &amount, const QString &deadline);

private:
    Ui::ScholarshipInfo *ui;
};

#endif // SCHOLARSHIPINFO_H
