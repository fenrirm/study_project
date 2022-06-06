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
#include <QDataStream>

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

// sign up realization
void MainWindow::on_signup_clicked()
{
    user u1(ui->nameLine->text(), ui->surnameLine->text(),
            ui->idLine->text(), ui->id2Line->text(), ui->passwordLine->text());
    u1.setName(ui->nameLine->text());
    u1.setSurname(ui->surnameLine->text());
    u1.setId(ui->idLine->text());
    u1.setSecondId(ui->id2Line->text());
    u1.setPassword(ui->passwordLine->text());

    //binary realization adding to file
    QFile bFile("user.dat");
    QDataStream out(&bFile);
    QDataStream in(&bFile);
    bool flag=true;
    user Line(ui->nameLine->text(), ui->surnameLine->text(), ui->idLine->text(),
              ui->id2Line->text(), ui->passwordLine->text());
    if(bFile.open(QIODevice::ReadOnly))
    {
        while(!in.atEnd())
        {
            in>>Line;
            qDebug()<<Line.getId();
            qDebug()<<u1. getId();
            if(Line.getId()==u1.getId())
            {
                flag=false;
                qWarning("The user with the same id is already exists!");
                return;
            }
        }
        bFile.close();
    }
    else
    {
        qWarning("Could not open the file!");
    }
    if(flag)
    {
        if(bFile.open(QIODevice::Append | QIODevice::Text))
        {
            out<<u1.getName()<<&Qt::endl;
            out<<u1.getSurname()<<&Qt::endl;
            out<<u1.getId()<<&Qt::endl;
            out<<u1.getSecondId()<<&Qt::endl;
            out<<u1.getPassword()<<&Qt::endl;
            bFile.close();
        }
        else
        {
            qWarning("Could not open the file");
        }
    }





    //adding to file
    QFile file;
    file.setFileName("user.txt");
    QTextStream textStream(&file);
    QTextStream writeStream(&file);
//    QTextStream readStream(&file);
    QString line;
    //bool flag=true;
    if(file.open(QIODevice::ReadOnly))
    {
        while(!textStream.atEnd())
        {
            textStream>>line;
            if(line==u1.getId())
            {
                qWarning("The user with the same id is already exists");
                //flag=false;
                return;
            }
        }
        //if (flag==false)
        //{
         //   qWarning("The user with the same login is already exists");
        //}
        file.close();
        if(file.open(QIODevice::Append)| (QIODevice::Text))
        {
            writeStream<<u1.getName()<<Qt::endl;
            writeStream<<u1.getSurname()<<Qt::endl;
            writeStream<<u1.getId()<<Qt::endl;
            writeStream<<u1.getSecondId()<<Qt::endl;
            writeStream<<u1.getPassword()<<Qt::endl;
            file.close();
        }
        else
        {
             qWarning("Could not open file");
        }

    }
    else
    {
         qWarning("Could not open file");
    }
//    loginFile.close();
//    passwordFile.close();

//    if(QFile::exists("user.txt"))
//    {
//    qDebug() << "Файл существует";
//    }



}

// log in realization
void MainWindow::on_LogIn_clicked()
{
    QFile file;
    file.setFileName("user.txt");
//    QFile loginFile;
//    QFile passwordFile;
//    loginFile.setFileName("login.txt");
//    passwordFile.setFileName("password.txt");
   // secondwindow *window = new secondwindow();
    bool flag = true;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
//        QTextStream readStream(&loginFile);
//        QTextStream readStream2(&passwordFile);
        QTextStream readStream(&file);
        while(!readStream.atEnd() )
        {
            QString line, line2;
            readStream >> line;            
            if(line==ui->Id->text())
            { 
                readStream>>line2;
                if(line2==ui->Password->text())
                {
                    qDebug()<<"You have succesfully logged in!";
                    //                qDebug()<<"You've succesfully authorized!";
                    //                window->show();
                    //                this->close();
                    flag = false;
                    break;
                }

            }

        }
            if (flag)
        {
            qDebug()<<"You have entered wrong login or this user doesn't exist!";
        }

    }
    file.close();

//    loginFile.close();
//    passwordFile.close();





}

