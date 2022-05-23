#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>//>
#include "user.h"//"
#include "QDebug"
#include <QLineEdit>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "secondwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText("Enter your name");
    ui->surnameLine->setPlaceholderText("Enter your surname");
    ui->idLine->setPlaceholderText("Enter your id");
    ui->id2Line->setPlaceholderText("Are you a student or a teacher?");
    ui->passwordLine->setPlaceholderText("Enter a password ");
    ui->Id->setPlaceholderText("Enter your Id");
    ui->Password->setPlaceholderText("Enter your pa;ssword");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signup_clicked()
{
    user u1(ui->nameLine->text(), ui->surnameLine->text(),
            ui->idLine->text(), ui->id2Line->text(), ui->passwordLine->text());
    u1.setName(ui->nameLine->text());
    u1.setSurname(ui->surnameLine->text());
    u1.setId(ui->idLine->text());
    u1.setSecondId(ui->id2Line->text());
    u1.setPassword(ui->passwordLine->text());

    //adding to file
    QFile file;
    file.setFileName("user.txt");
    QFile loginFile;
    QFile passwordFile;
    loginFile.setFileName("login.txt");
    passwordFile.setFileName("password.txt");

    if (file.open(QIODevice::Append| QIODevice::Text)&&loginFile.open(QIODevice::Append| QIODevice::Text)
            &&passwordFile.open(QIODevice::Append| QIODevice::Text))
    {
       QTextStream writeStream(&file);
       writeStream<<u1.getName()<<Qt::endl;
       writeStream<<u1.getSurname()<<Qt::endl;
       writeStream<<u1.getSecondId()<<Qt::endl;
       QTextStream writeStream2(&loginFile);
       writeStream2<<u1.getId()<<Qt::endl;
       QTextStream writeStream3(&passwordFile);
       writeStream3<<u1.getPassword()<<Qt::endl;
    }
    else
    {
         qWarning("Could not open file");
    }
    file.close();
    loginFile.close();
    passwordFile.close();

//    if(QFile::exists("user.txt"))
//    {
//    qDebug() << "Файл существует";
//    }



}


void MainWindow::on_LogIn_clicked()
{
    QFile file;
    file.setFileName("user.txt");
    QFile loginFile;
    QFile passwordFile;
    loginFile.setFileName("login.txt");
    passwordFile.setFileName("password.txt");
    secondwindow *window = new secondwindow();
    if(loginFile.open(QIODevice::ReadOnly | QIODevice::Text)
            && passwordFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream readStream(&loginFile);
        QTextStream readStream2(&passwordFile);
        while(!readStream.atEnd() )
        {

            QString line, line2;
            readStream >> line;
            readStream2 >> line2;
            if((line==ui->Id->text()) &&( line2==ui->Password->text()))
            { 
                qDebug()<<"You've succesfully authorized!";
                window->show();
                this->close();
                break;

            }
            else
            {
                qDebug()<<"Cannot open the window";
            }



        }

    }
    loginFile.close();
    passwordFile.close();





}

