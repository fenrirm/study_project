#ifndef FILECLASS_H
#define FILECLASS_H
#pragma once
#include <QString>
#include "mainwindow.h"
#include "user.h"
#include "classroom.h"
#include "teacherwindow.h"

class fileclass
{
public:
    virtual void writeToFile(QString& path,  MainWindow* mainwindow, TeacherWindow* teacherwindow, user u1, Classroom classroom1)=0;
     void readFromFile(QString& path, MainWindow* mainwindow, TeacherWindow* teacherwindow, QString id, QString pass);
    //bool checkUnic(const QString &path,QString IDtoCheck);

};

#endif // FILECLASS_H
