#include "user.h"
#include <QString>
#include <QLineEdit>
#include "mainwindow.h"
#include <QDebug>
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

QDataStream &operator>>(QDataStream &in, user &t)
{
    QString st;
    in >> st;
    t.NameLine = st;
    in >> st;
    t.SurnameLine = st;
    in >> st;
    t.IdLine = st;
    in >> st;
    t.Id2Line = st;
    in >> st;
    t.Password = st;
    qDebug()<<t.SurnameLine;
    return in;
}

QDataStream &operator<<(QDataStream &out, user &t)
{
    out << t.NameLine<<"\n";
    out << t.SurnameLine<<"\n";
    out << t.IdLine<<"\n";
    out << t.Id2Line<<"\n";
    out << t.Password<<"\n";
    qDebug()<<t.SurnameLine<<"\n";
    return out;
}



