#ifndef RESOURCES_H
#define RESOURCES_H


#include <QDialog>
#include <QComboBox>


namespace Ui {
class resources;
}

class resources : public QDialog
{
    Q_OBJECT

public:
    explicit resources(QWidget *parent = nullptr);
    ~resources();
     QComboBox *comboBox_scholarshipType;

private slots:
   void on_pushButton_Scholarship_clicked();
   void on_pushButton_backtos_clicked();





   void on_pushButton_Programs_clicked();

   private:
    Ui::resources *ui;
    QString scholarships[3][3];

    //void loadScholarshipContent();
};

#endif // RESOURCES_H
