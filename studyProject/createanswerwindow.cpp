#include "createanswerwindow.h"
#include "ui_createanswerwindow.h"

createanswerwindow::createanswerwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createanswerwindow)
{
    ui->setupUi(this);
}

createanswerwindow::~createanswerwindow()
{
    delete ui;
}
