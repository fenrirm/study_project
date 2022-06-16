#include "teacherwindow.h"
#include "classroomfile.h"


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
   writeclassroom.writeToFile(path, this, u, classroom);
}

