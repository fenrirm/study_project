#ifndef FILECLASS_H
#define FILECLASS_H
#pragma once
#include <QString>
#include "mainwindow.h"
#include "user.h"
#include "classroom.h"

class fileclass
{
public:
    virtual void writeToFile(QString& path,  MainWindow* mainwindow, user u1, Classroom classroom1);
    virtual void readFromFile(QString& path, MainWindow* mainwindow, QString id, QString pass);
    bool checkUnic(const QString &path,QString IDtoCheck);
};

#endif // FILECLASS_H
