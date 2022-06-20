#include "createopentaskwindow.h"
#include "ui_createopentaskwindow.h"

createOpenTaskWindow::createOpenTaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createOpenTaskWindow)
{
    ui->setupUi(this);
}

createOpenTaskWindow::~createOpenTaskWindow()
{
    delete ui;
}
