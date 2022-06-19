#include "studenttestwindow.h"
#include "ui_studenttestwindow.h"

studenttestwindow::studenttestwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studenttestwindow)
{
    ui->setupUi(this);
}

studenttestwindow::~studenttestwindow()
{
    delete ui;
}
