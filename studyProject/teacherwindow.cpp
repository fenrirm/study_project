#include "teacherwindow.h"
#include "classroomfile.h"
#include "mainwindow.h"
#include "testfactory.h"
#include "createtestwindow.h"
#include "createopentaskwindow.h"


TeacherWindow::TeacherWindow(QString id, QString name, QString surname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    ui->id->setText(id);
    ui->name->setText(name);
    ui->surname->setText(surname);
    ui->nameClassLine->setPlaceholderText("Enter a name of a class");
    ui->classroomName->setPlaceholderText("Enter a name of a classroom");
    ui->testName->setPlaceholderText("Eneter a title of the test");
    ui->openTaskName->setPlaceholderText("Enter a title of the open task");

    //Create and add label to classromm
//    QLabel::QWidget* label= new QLabel("Some text");
//    ui->ClassLayout->addWidget(label);
//    label->show();
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
            if(obj[obj.keys()[0]].toObject()["classroomId"].toString()==ui->id->text()){
                QLabel::QWidget* label= new QLabel(obj.keys()[0]);
                ui->ClassLayout->addWidget(label);
                label->show();
            }
        }
    }

};
TeacherWindow::~TeacherWindow()
{
    delete ui;
}


void TeacherWindow::on_createClass_clicked()
{
   Classroom classroom(ui->id->text(), ui->nameClassLine->text());
   classroom.setId(ui->id->text());
   classroom.setName(ui->nameClassLine->text());
   user u(nullptr,nullptr,nullptr,nullptr,nullptr);
   u.setName(nullptr);
   u.setSurname(nullptr);
   u.setId(nullptr);
   u.setIsTeacher(nullptr);
   u.setPassword(nullptr);
   QString path="D:/oop/Qt/studyProject/classroom.json";
   classroomfile writeclassroom;
   writeclassroom.writeToFile(path, nullptr, this, u, classroom);
}


void TeacherWindow::on_logout_clicked()
{
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    this->close();
}

bool TeacherWindow::checkUnic(const QString &path,QString NametoCheck)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            if(obj.keys()[0] == NametoCheck)
            {
                return false;
            }
        }

    }
    return true;
}

void TeacherWindow::on_createTest_clicked()
{
   createTestWindow* testwindow = new createTestWindow(ui->testName->text());
   testwindow->teacherId=ui->id->text();
   testwindow->classroomName=ui->classroomName->text();
   QString path = "D:/oop/Qt/studyProject/tests.json";
   bool unic = checkUnic(path,ui->testName->text());
   QFile f(path);
   if(f.open(QIODevice::ReadOnly))
   {
       QByteArray bytes = f.readAll();
       f.close();
       QJsonDocument doc (QJsonDocument::fromJson(bytes));
       QJsonArray arr = doc.array();
      QJsonDocument doc2(arr);
      QFile file (path);
      if(unic)
      {
          testwindow->show();
      }
      else
      {
          QMessageBox::critical(this,"","The test with the same name is already exist!");
      }
   }


}


void TeacherWindow::on_ShowClassTasks_clicked()
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
            if((obj[obj.keys()[0]].toObject()["clasroomName"].toString()==ui->ClassNameToShow->text() )&&
                   (obj[obj.keys()[0]].toObject()["teacheID"].toString() == ui->id->text())){
                QLabel::QWidget* label= new QLabel(obj.keys()[0]);
                ui->TaskLayout->addWidget(label);
                label->show();
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
            if((obj[obj.keys()[0]].toObject()["clasroomName"].toString()==ui->ClassNameToShow->text() )&&
                   (obj[obj.keys()[0]].toObject()["teacheID"].toString() == ui->id->text())){
                QLabel::QWidget* label= new QLabel(obj.keys()[0]);
                ui->TaskLayout->addWidget(label);
                label->show();
            }
        }
    }

}


void TeacherWindow::on_createOpenTask_clicked()
{
    createOpenTaskWindow* opentaskwindow = new createOpenTaskWindow(ui->openTaskName->text());
    opentaskwindow->teacherId=ui->id->text();
    opentaskwindow->classroomName=ui->classroomName->text();
    QString path = "D:/oop/Qt/studyProject/opentasks.json";
    bool unic = checkUnic(path,ui->openTaskName->text());
    QFile f(path);
    if(f.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = f.readAll();
        f.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr = doc.array();
       QJsonDocument doc2(arr);
       QFile file (path);
       if(unic)
       {
           opentaskwindow->show();
       }
       else
       {
           QMessageBox::critical(this,"","The test with the same name is already exist!");
       }
    }

}


void TeacherWindow::on_showStudents_clicked()
{
     QString path = "D:/oop/Qt/studyProject/classroom.json";
    QFile file(path);
    bool isUnic=true;
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();

            if((obj.keys()[0]==ui->className->text() ))
            {
               // qDebug()<<"if";
                 isUnic=false;
                foreach(const QJsonValue& value1,  obj[obj.keys()[0]].toObject()["studentsId"].toArray())
                {
                   QLabel::QWidget* label= new QLabel(value1.toString());
                    ui->studentsLayout->addWidget(label);
                     label->show();
                }

            }

        }
        if(isUnic)
        {
            QMessageBox::critical(this,"","You have entered wrong classroom name or this classroom doesn't exist");

        }
    }

}

