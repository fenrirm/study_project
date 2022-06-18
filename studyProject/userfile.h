#ifndef USERFILE_H
#define USERFILE_H
#pragma once
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include <QFile>
#include "user.h"
#include "teacherwindow.h"
#include "secondwindow.h"
#include "teacherwindow.h"
#include "mainwindow.h"
#include "fileclass.h"
#include "classroom.h"



class userfile:public fileclass
{
public:
    userfile();
    void writeToFile(QString& path,  MainWindow* mainwindow,TeacherWindow* teacherwindow, user u1, Classroom classroom1) override;
    void readFromFile(QString& path, MainWindow* mainwindow,TeacherWindow* teacherwindow, QString id, QString pass);
    bool checkUnic(const QString &path, QString IDtoCheck);
};

#endif // USERFILE_H
