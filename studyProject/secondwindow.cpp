#include "secondwindow.h"
#include "qdebug.h"
#include "ui_secondwindow.h"
#include "classroomfile.h"
#include "mainwindow.h"
#include "createanswerwindow.h"
#include "opentaskanswerwindow.h"

secondwindow::secondwindow(QString id, QString name, QString surname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    ui->id->setText(id);
    ui->name->setText(name);
    ui->surname->setText(surname);

    QFile file("D:/oop/Qt/studyProject/classroom.json");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            foreach(const QJsonValue& check,obj[obj.keys()[0]].toObject()["studentsId"].toArray()){
                if(check.toString() == ui->id->text()){
                    QLabel::QWidget* label= new QLabel(obj.keys()[0]);
                    ui->ClassLayout->addWidget(label);
                    label->show();
                    break;
                }
            }

        }
    }
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


void secondwindow::on_ShowClassTasks_clicked()
{
    QList<QWidget *> widgets = ui->verticalWidget_2->findChildren<QWidget *>();
    foreach(QWidget * widget, widgets)
    {
        delete widget;
    }

    QFile file("D:/oop/Qt/studyProject/tests.json");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();

        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            obj[obj.keys()[0]].toObject()["studentsGrades"].toObject();
            if((obj[obj.keys()[0]].toObject()["clasroomName"].toString()==ui->ClassNameToShow->text() ))
            {
                if(!(obj[obj.keys()[0]].toObject()["studentsGrades"].toObject().contains(ui->id->text())))
                {
                QLabel::QWidget* label= new QLabel(obj.keys()[0]);
                ui->TaskLayout->addWidget(label);
                label->show();
                qDebug()<<ui->id->text();
                }
            }
        }
    }

    QFile file1("D:/oop/Qt/studyProject/opentasks.json");
    if(file1.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file1.readAll();
        file1.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            if((obj[obj.keys()[0]].toObject()["clasroomName"].toString()==ui->ClassNameToShow->text() )){
                QLabel::QWidget* label= new QLabel(obj.keys()[0]);
                ui->TaskLayout->addWidget(label);
                label->show();
            }
        }
    }
}


void secondwindow::on_DoTask_clicked()
{
    QFile fileTestTask("D:/oop/Qt/studyProject/tests.json");
    if(fileTestTask.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = fileTestTask.readAll();
        fileTestTask.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            if((obj[obj.keys()[0]].toObject()["clasroomName"].toString()==ui->ClassNameToShow->text() &&
                obj.keys()[0] == ui->TaskToDo->text())){
                createanswerwindow* ansWindow = new createanswerwindow(ui->TaskToDo->text());
                ansWindow->studentId=ui->id->text();
                ansWindow->show();
            }
        }
    }

    QFile fileOpenTask("D:/oop/Qt/studyProject/opentasks.json");
    if(fileOpenTask.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = fileOpenTask.readAll();
        fileOpenTask.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            if((obj[obj.keys()[0]].toObject()["clasroomName"].toString()==ui->ClassNameToShow->text() &&
                obj.keys()[0] == ui->TaskToDo->text())){
                OpenTaskAnswerWindow* ansWindow = new OpenTaskAnswerWindow(ui->TaskToDo->text());
                ansWindow->studentId=ui->id->text();
                ansWindow->show();
            }
        }
    }
}


void secondwindow::on_showGrades_clicked()
{
    QFile file("D:/oop/Qt/studyProject/tests.json");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
                if((obj[obj.keys()[0]].toObject()["studentsGrades"].toObject().contains(ui->id->text())))
                {
                QLabel::QWidget* label= new QLabel(obj.keys()[0]+"-"+obj[obj.keys()[0]].toObject()["studentsGrades"].toObject()[ui->id->text()].toString());
                ui->gradesLayout->addWidget(label);
                label->show();
                }

        }
    }
     QFile f("D:/oop/Qt/studyProject/opentasks.json");
    if(f.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = f.readAll();
        f.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
                if((obj[obj.keys()[0]].toObject()["studentsGrades"].toObject().contains(ui->id->text())))
                {
                QLabel::QWidget* label= new QLabel(obj.keys()[0]+"-"+obj[obj.keys()[0]].toObject()["studentsGrades"].toObject()[ui->id->text()].toString());
                ui->gradesLayout->addWidget(label);
                label->show();
                }

        }
    }


}

