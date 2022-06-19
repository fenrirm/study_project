#include "teacherwindow.h"
#include "classroomfile.h"
#include "mainwindow.h"
#include "testfactory.h"
#include "writewordfactory.h"
#include "createtestwindow.h"


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


void TeacherWindow::on_logout_clicked()
{
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    this->close();
}


void TeacherWindow::on_createTest_clicked()
{
   createTestWindow* testwindow = new createTestWindow(ui->testName->text());
   testwindow->teacherId=ui->id->text();
   testwindow->classroomName=ui->classroomName->text();
   testwindow->show();

}

