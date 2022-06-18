#include "teacherwindow.h"
#include "classroomfile.h"
#include "createtaskwindow.h"
#include "task.h"
#include "questionfactory.h"
#include "testfactory.h"
#include "ansfactory.h"
#include "mainwindow.h"

TeacherWindow::TeacherWindow(QString id, QString name, QString surname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    ui->id->setText(id);
    ui->name->setText(name);
    ui->surname->setText(surname);
    ui->nameClassLine->setPlaceholderText("Enter a name of a class");
}

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





void TeacherWindow::on_createTask_clicked()
{
    QString type;

    if(ui->radioButton_type1->isChecked()){
        type="1";

    }else  if(ui->radioButton_type2->isChecked()){
        type="2";
    }

    Task* newTask = new Task(type,ui->id->text(),ui->lineEditClassroom->text(),ui->lineEditTask->text());

    CreateTaskWindow* taskCreateWindow = new CreateTaskWindow(*newTask,nullptr);
    taskCreateWindow->show();
    this->close();
}



void TeacherWindow::on_logout_clicked()
{
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    this->close();
}

