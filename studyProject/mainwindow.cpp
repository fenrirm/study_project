#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondwindow.h"
#include <QString>
#include "user.h"
#include <QDebug>
#include <QLineEdit>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QApplication>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include "teacherwindow.h"
#include "userfile.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText("Enter your name");
    ui->surnameLine->setPlaceholderText("Enter your surname");
    ui->idLine->setPlaceholderText("Enter your id");
    ui->passwordLine->setPlaceholderText("Enter a password ");
    ui->Id->setPlaceholderText("Enter your Id");
    ui->Password->setPlaceholderText("Enter your password");
}

MainWindow::~MainWindow()
{
    delete ui;
}


// sign up realization
void MainWindow::on_signup_clicked()
{
    QString path = "D:/oop/Qt/studyProject/user.json";
    QString flag;
    if(ui->Teacher->isChecked())
    {
        flag="true";
    }
    else
    {
        flag="false";
    }
    user u1(ui->nameLine->text(), ui->surnameLine->text(),
            ui->idLine->text(),flag,ui->passwordLine->text());
    u1.setName(ui->nameLine->text());
    u1.setSurname(ui->surnameLine->text());
    u1.setId(ui->idLine->text());
    u1.setPassword(ui->passwordLine->text());
    Classroom classroom1(nullptr, nullptr);
    classroom1.setId(nullptr);
    classroom1.setName(nullptr);
    userfile writeuser;
    writeuser.writeToFile(path, this, nullptr, u1, classroom1);
}

// log in realization
void MainWindow::on_LogIn_clicked()
{
    QString path = "D:/oop/Qt/studyProject/user.json";
    userfile readuser;
    readuser.readFromFile(path, this, nullptr, ui->Id->text(),ui->Password->text());
}

