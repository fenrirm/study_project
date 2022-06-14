#ifndef USERFILE_H
#define USERFILE_H
#include "user.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include "teacherwindow.h"
#include <QFile>
#include "secondwindow.h"
#include "teacherwindow.h"
#include "mainwindow.h"
#include "fileclass.h"


class userfile:public fileclass
{
public:
    userfile();
    void writeToFile(QString& path,  MainWindow* mainwindow, user u1) override;
    void readFromFile(QString& path, MainWindow* mainwindow, QString id, QString pass)override;
    bool checkUnic(const QString &path, QString IDtoCheck);
};

#endif // USERFILE_H
