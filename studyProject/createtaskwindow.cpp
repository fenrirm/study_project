#include "createtaskwindow.h"
#include "ui_createtaskwindow.h"
#include <QScrollArea>
#include "task.h"
#include "questionfactory.h"
#include "question.h"


CreateTaskWindow::CreateTaskWindow(Task task,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTaskWindow)
{

    ui->setupUi(this);
    task=task;
}

CreateTaskWindow::~CreateTaskWindow()
{
    delete ui;
}


int checkCorrectAns(bool one,bool two,bool three,bool four){
    if(one){
        return 1;
    }
    if(two){
        return 2;
    }
    if(three){
        return 3;
    }
    if(four){
        return 4;
    }
    return 0;
}

void CreateTaskWindow::on_createButton_clicked()
{
    TestFactory* factory;

    int testAns=checkCorrectAns(ui->radioButton1_1->isChecked(),ui->radioButton1_2->isChecked(),ui->radioButton1_3->isChecked(),ui->radioButton1_4->isChecked());
    Question* test1 = factory->createQuestion(ui->lineEditTest1->text(),testAns);
    this->task->pushQusetion(test1);

    this->close();
}

