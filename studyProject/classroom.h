#ifndef CLASSROOM_H
#define CLASSROOM_H
#pragma once
#include <QString>
#include <vector>
#include "user.h"


class Classroom
{
private:
    QString id;
    QString name;
    std::pair <user,std::vector <std::pair <QString,int>>> gradeBook;// пара студент і його журнал тест + оцінка

public:
    Classroom(QString Id, QString Name);
    void setId(QString Id);
    QString getId();
    void setName(QString Name);
    QString getName();

};



#endif // CLASSROOM_H
