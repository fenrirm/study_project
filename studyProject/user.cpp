#include "user.h"
#include <QString>
#include <QLineEdit>
#include "mainwindow.h"
#include <QDebug>
#include "./ui_mainwindow.h"


user::user(QString nameLine, QString surnameLine, QString idLine,bool is_Teacher, QString password)
{
    this->setName(nameLine);
    this->setSurname(surnameLine);
    this->setId(idLine);
    this->setIs_Teacher(is_Teacher);
    this->setPassword(password);
}

user::user(){
    this->IdLine =nullptr;
    this->NameLine=nullptr;
    this->SurnameLine=nullptr;
    this->Is_Teacher=NULL;
    this->Password=nullptr;
}

void user::setId(QString id)
{
    this->IdLine = id;
}

QString user::getId()
{
    return IdLine;
}



void user::setName(QString nameLine)
{
    this->NameLine = nameLine;
}

QString user::getName()
{
   return NameLine;

}

void user::setSurname(QString surnameLine)
{
    this->SurnameLine = surnameLine;
}

QString user::getSurname()
{
    return SurnameLine;
}
void user::setIs_Teacher(bool is_Teacher)
{
    this->Is_Teacher = is_Teacher;
}

bool user::getIs_Teacher()
{
    return Is_Teacher;
}

void user::setPassword(QString password)
{
    this->Password = password;
}

QString user::getPassword()
{
    return Password;
}




