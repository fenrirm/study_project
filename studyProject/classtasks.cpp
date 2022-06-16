#include "classtasks.h"
#include "ui_classtasks.h"

classTasks::classTasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classTasks)
{
    ui->setupUi(this);
}

classTasks::~classTasks()
{
    delete ui;
}
