// program.h
#ifndef PROGRAM_H
#define PROGRAM_H

#include <QString>

class Program {
public:
    Program(const QString& name, const QString& description)
        : name(name), description(description) {}

    QString getName() const {
        return name;
    }

    QString getDescription() const {
        return description;
    }

private:
    QString name;
    QString description;
};

#endif // PROGRAM_H
