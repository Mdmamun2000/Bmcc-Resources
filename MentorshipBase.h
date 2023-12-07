#ifndef MENTORSHIPBASE_H
#define MENTORSHIPBASE_H

#include <QDialog>
#include <QVector>


class MentorshipBase : public QDialog
{
    Q_OBJECT

public:
    MentorshipBase(QWidget *parent = nullptr);
    virtual ~MentorshipBase();

private slots:
    virtual void on_pushButton_Peerconnect_clicked() = 0;

protected:
    Ui::mentorship *ui;
};

#endif // MENTORSHIPBASE_H
