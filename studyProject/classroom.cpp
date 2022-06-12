#include "classroom.h"



Classroom::Classroom(QString Id, QString Name)
{   
    id=Id;
    name=Name;
}


void Classroom::setId(QString Id)
{
    id=Id;
}

QString Classroom::getId()
{
    return id;
}

void Classroom::setName(QString Name)
{
    name=Name;
}

QString Classroom::getName()
{
    return name;
}


