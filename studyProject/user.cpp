#include "user.h"

user::user()
{

}

user::user(QString nameLine, QString surnameLine, QString idLine, QString isTeacher, QString password)
{
    NameLine=nameLine;
    SurnameLine=surnameLine;
    IdLine=idLine;
    IsTeacher=isTeacher;
    Password=password;
}

void user::setId(QString id)
{
    IdLine = id;
}

QString user::getId()
{
    return IdLine;
}

void user::setIsTeacher(QString isTeacher)
{
    IsTeacher = isTeacher;
}

QString user::getIsTeacher()
{
    return IsTeacher;
}

void user::setName(QString nameLine)
{
    NameLine = nameLine;
}

QString user::getName()
{
   return NameLine;

}

void user::setSurname(QString surnameLine)
{
    SurnameLine = surnameLine;
}

QString user::getSurname()
{
    return SurnameLine;
}
void user::setPassword(QString password)
{
    Password = password;
}

QString user::getPassword()
{
    return Password;
}




