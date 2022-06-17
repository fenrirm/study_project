#ifndef CLASSROOMFILE_H
#define CLASSROOMFILE_H
#pragma once
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include <QFile>
#include "user.h"
#include "fileclass.h"
#include "classroom.h"
#include "teacherwindow.h"
#include "secondwindow.h"

class classroomfile
{
public:
    classroomfile();
    void writeToFile(QString& path,  TeacherWindow* mainwindow, user u1, Classroom classroom1) ;
    void readFromFile(QString& path, TeacherWindow* mainwindow, QString id, QString pass);
    bool checkUnic(const QString &path, QString nameToCheck);
    void addStudent(QString& path, secondwindow* studentwindow, QString teacherId, QString name, QString studentId);
};

#endif // CLASSROOMFILE_H
