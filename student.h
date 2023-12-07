#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Senior {
public:
    QString name;

    Senior(const QString& n);

    QString getName() const;  // Add this line
};

class Freshman {
public:
    QString name;
    Senior* connectedSenior; // Pointer to connected Senior

    Freshman(const QString& n);

    void connectWithSenior(Senior& senior);

    QString getName() const;

    QString getConnectedSeniorName() const;
};

#endif // STUDENT_H
