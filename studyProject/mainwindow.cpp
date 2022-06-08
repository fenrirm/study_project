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
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText("Enter your name");
    ui->surnameLine->setPlaceholderText("Enter your surname");
    ui->idLine->setPlaceholderText("Enter your id");
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
    user* u1 =  new user(ui->nameLine->text(),ui->surnameLine->text(),ui->idLine->text(),true,ui->passwordLine->text());



    bool unic = true;

    user* tmp= new user();
    QFile file("userDB.txt");
//read from file
    if(!file.open(QFile::ReadOnly)){
        QMessageBox::warning(this,"lul","not open");
    }else{
        while(file.read((char*)&tmp,sizeof(user))){
            QTextStream out(&file);
            qDebug()<<sizeof(user)<<" ";
            qDebug()<<tmp->getName()<<" ";

        }
        file.seek(0);
        file.close();
    }
delete tmp;
//write to file
        if(unic){
            if(!file.open(QFile::WriteOnly)){
                QMessageBox::warning(this,"lul","not write open");
            }else{
                file.write((char*)&u1,sizeof(user));
                file.flush();
                file.close();
            }
        }
        file.close();
    delete u1;
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

