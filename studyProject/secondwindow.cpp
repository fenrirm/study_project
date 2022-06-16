#include "secondwindow.h"
#include "qdebug.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QString id, QString name, QString surname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    ui->id->setText(id);
    ui->name->setText(name);
    ui->surname->setText(surname);
}

secondwindow::~secondwindow()
{
    delete ui;
}



