#include "opentaskanswerwindow.h"
#include "ui_opentaskanswerwindow.h"

OpenTaskAnswerWindow::OpenTaskAnswerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenTaskAnswerWindow)
{
    ui->setupUi(this);
}

OpenTaskAnswerWindow::~OpenTaskAnswerWindow()
{
    delete ui;
}
