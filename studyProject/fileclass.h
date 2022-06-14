#ifndef FILECLASS_H
#define FILECLASS_H
#include <QString>
#include "mainwindow.h"
#include "user.h"

class fileclass
{
public:
    //virtual void writeToFile(QString& path, MainWindow* window)=0;
    virtual void writeToFile(QString& path,  MainWindow* mainwindow, user u1)=0;
    //virtual void readFromFile(QString& path, MainWindow* window)=0;
    virtual void readFromFile(QString& path, MainWindow* mainwindow, QString id, QString pass)=0;
};

#endif // FILECLASS_H
