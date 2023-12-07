#ifndef PEER_H
#define PEER_H

#include <QDialog>

namespace Ui {
class peer;
}

class peer : public QDialog
{
    Q_OBJECT

public:
    explicit peer(QWidget *parent = nullptr);
    ~peer();
    void showConnectionInfo(const QString& info);
    void saveQuestionToFile(const QString& question);

private slots:
    void on_pushButton_Pback_clicked();

private:
    Ui::peer *ui;
};

#endif // PEER_H
