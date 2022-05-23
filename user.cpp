#include "user.h"
#include <QString>
#include <QLineEdit>
#include "mainwindow.h"
#include "./ui_mainwindow.h"


user::user(QString nameLine, QString surnameLine, QString idLine, QString id2Line, QString password)
{

}

void user::setId(QString id)
{
    IdLine = id;
}

QString user::getId()
{
    return IdLine;
}

void user::setSecondId(QString id2Line)
{
    Id2Line = id2Line;
}

QString user::getSecondId()
{
    return Id2Line;
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


