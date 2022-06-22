#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H
#pragma once
#include "classroom.h"
#include "user.h"
#include "ui_teacherwindow.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>
#include <QMainWindow>


namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QString id, QString name, QString surname, QWidget *parent = nullptr);
    bool checkUnic(const QString &path,QString NametoCheck);
    ~TeacherWindow();

private slots:
    void on_createClass_clicked();
    void on_logout_clicked();
    void on_createTest_clicked();
    void on_ShowClassTasks_clicked();
    void on_createOpenTask_clicked();

private:
    Ui::TeacherWindow *ui;
};

#endif // TEACHERWINDOW_H
