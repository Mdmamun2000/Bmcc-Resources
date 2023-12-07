#include "student.h"

Senior::Senior(const QString& n) : name(n) {}

QString Senior::getName() const {
    return name;
}

Freshman::Freshman(const QString& n) : name(n), connectedSenior(nullptr) {}

void Freshman::connectWithSenior(Senior& senior) {
    connectedSenior = &senior;
}

QString Freshman::getName() const {
    return name;
}

QString Freshman::getConnectedSeniorName() const {
    return (connectedSenior ? connectedSenior->getName() : "None");
}
