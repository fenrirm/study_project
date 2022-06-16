#ifndef CLASSROOM_H
#define CLASSROOM_H
#pragma once
#include <QString>


class Classroom
{
private:
    QString id;
    QString name;

public:
    Classroom(QString Id, QString Name);
    void setId(QString Id);
    QString getId();
    void setName(QString Name);
    QString getName();

};



#endif // CLASSROOM_H
