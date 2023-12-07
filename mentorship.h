#ifndef MENTORSHIP_H
#define MENTORSHIP_H

#include <QDialog>
#include <QVector>
#include "ui_mentorship.h"
#include "student.h"
#include "peer.h"

class mentorship : public QDialog
{
    Q_OBJECT

public:
    mentorship(QWidget *parent = nullptr);
    ~mentorship();

private slots:
    void on_pushButton_Peerconnect_clicked();

    void on_pushButton_Mback_clicked();

private:
    Ui::mentorship *ui;
    peer *Peer;

    QVector<Freshman> freshmen; // Aggregation
    QVector<Senior> seniors;    // Aggregation

    void createStudents();
    Senior getRandomSenior();
};

#endif // MENTORSHIP_H
