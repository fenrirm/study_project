#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "teacher.h"

TeacherWindow::TeacherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::on_createClass_clicked()
{


}

