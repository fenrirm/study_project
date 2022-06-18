#include "createtaskwindow.h"
#include "ui_createtaskwindow.h"
#include <QScrollArea>

CreateTaskWindow::CreateTaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTaskWindow)
{
    ui->setupUi(this);
}

CreateTaskWindow::~CreateTaskWindow()
{
    delete ui;
}
