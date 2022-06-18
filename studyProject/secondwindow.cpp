#include "secondwindow.h"
#include "qdebug.h"
#include "ui_secondwindow.h"
#include "classroomfile.h"
#include "mainwindow.h"

secondwindow::secondwindow(QString id, QString name, QString surname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    ui->id->setText(id);
    ui->name->setText(name);
    ui->surname->setText(surname);
}

secondwindow::~secondwindow()
{
    delete ui;
}




void secondwindow::on_connectToClass_clicked()
{
    classroomfile student;
    QString path="D:/oop/Qt/studyProject/classroom.json";
    student.addStudent(path, this, ui->teacherId->text(), ui->classroomName->text(), ui->id->text());
}


void secondwindow::on_logOut_clicked()
{
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    this->close();
}

