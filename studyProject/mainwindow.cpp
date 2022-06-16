#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondwindow.h"
#include <QString>
#include "user.h"
#include <QDebug>
#include <QLineEdit>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QApplication>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include "teacherwindow.h"
#include "userfile.h"


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
    ui->Password->setPlaceholderText("Enter your password");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::createJson(const QString &path)

//{
//    QString flag;
//    if(ui->Teacher->isChecked())
//    {
//        flag="true";
//    }
//    else
//    {
//        flag="false";
//    }
//    user u1(ui->nameLine->text(), ui->surnameLine->text(),
//            ui->idLine->text(),flag,ui->passwordLine->text());
//    u1.setName(ui->nameLine->text());
//    u1.setSurname(ui->surnameLine->text());
//    u1.setId(ui->idLine->text());
//    u1.setPassword(ui->passwordLine->text());
//    QJsonObject user1;
//    QJsonObject obj;
//    obj.insert("name", u1.getName());
//    obj.insert("surname", u1.getSurname());
//    obj.insert("post", u1.getIsTeacher());
//    obj.insert("pass", u1.getPassword());

//    user1.insert(u1.getId(), obj);
//    bool unic = MainWindow::cheackUnic(path,u1.getId());
//    QFile f(path);
//    if(f.open(QIODevice::ReadOnly))
//    {

//        QByteArray bytes = f.readAll();
//        f.close();
//        QJsonDocument doc (QJsonDocument::fromJson(bytes));
//        QJsonArray arr = doc.array();
//        if(doc.isObject())
//        {

//            QJsonObject json = doc.object();
//            foreach(const QString& key, json.keys())
//            {
//                QJsonValue value = json.value(key);
//            }
//        }
//        arr.push_back(user1);
//        QJsonDocument doc2(arr);
//        QFile file (path);
//        if(unic){
//                    if(file.open(QIODevice::WriteOnly))
//                    {
//                        file.write(doc2.toJson());
//                        QMessageBox::about(this,"","You have succesfully signed up!");
//                        file.close();
//                    }
//                    else
//                    {
//                        QMessageBox::critical(this,"","file opened failed: ");
//                    }
//                }else{
//                    QMessageBox::critical(this,"","The user with the same id is already exists!");
//                }

//}

//}

//void MainWindow::readJson(const QString &path)
//{
//    QFile file(path);
//    if(file.open(QIODevice::ReadOnly))
//    {
//        QByteArray bytes = file.readAll();
//        file.close();
//        QJsonDocument doc (QJsonDocument::fromJson(bytes));
//        QJsonArray arr= doc.array();
//        foreach(const QJsonValue& value, arr)
//        {
//            QJsonObject obj = value.toObject();

//            if(obj.keys()[0]==ui->Id->text())
//            {
//                if(obj[obj.keys()[0]].toObject()["pass"].toString()==ui->Password->text())
//                {
//                    if( obj[obj.keys()[0]].toObject()["post"].toString()=="false")
//                    {
//                    secondwindow* window = new secondwindow(obj[obj.keys()[0]].toObject()["name"].toString(),
//                            obj[obj.keys()[0]].toObject()["surname"].toString());
//                    QMessageBox::about(this, "", "You have succesfully logged in");
//                    window->show();

//                    this->close();
//                    file.close();
//                    return;

//                    //delete window;
//                    }


//                    else /*if( obj[obj.keys()[0]].toObject()["post"].toString()=="true")*/
//                    {
//                        TeacherWindow *window2= new TeacherWindow(obj[obj.keys()[0]].toObject()["name"].toString(),
//                                obj[obj.keys()[0]].toObject()["surname"].toString());
//                        QMessageBox::about(this, "", "You nave succesfully logged in");
//                        window2->show();

//                        this->close();
//                       file.close();
//                       return;

//                        //delete window2;

//                    }

//                }
//                else
//                {
//                    QMessageBox::critical(this, "", "You have entered wrong password!");
//                    return;

//                }


//            }
////            else
////            {
////                QMessageBox::critical(this, "", "This user doesn't exist or you've entered wrong id");
////            }

//        }
//        QMessageBox::critical(this, "", "This user doesn't exist or you've entered wrong id");


//    }

//}

//bool MainWindow::cheackUnic(const QString &path,QString IDtoCheck)
//{
//    QFile file(path);
//    if(file.open(QIODevice::ReadOnly))
//    {
//        QByteArray bytes = file.readAll();
//        file.close();
//        QJsonDocument doc (QJsonDocument::fromJson(bytes));
//        QJsonArray arr= doc.array();
//        foreach(const QJsonValue& value, arr)
//        {
//            QJsonObject obj = value.toObject();
//            if(obj.keys()[0] == IDtoCheck)
//            {
//                return false;
//            }
//        }

//    }
//    return true;
//}

// sign up realization
void MainWindow::on_signup_clicked()
{
    QString path = "D:/Study/Term 2/OOOP/project/study_project/studyProject/user.json";
    QString flag;
    if(ui->Teacher->isChecked())
    {
        flag="true";
    }
    else
    {
        flag="false";
    }
    user u1(ui->nameLine->text(), ui->surnameLine->text(),
            ui->idLine->text(),flag,ui->passwordLine->text());
    u1.setName(ui->nameLine->text());
    u1.setSurname(ui->surnameLine->text());
    u1.setId(ui->idLine->text());
    u1.setPassword(ui->passwordLine->text());
    Classroom classroom1(nullptr, nullptr);
    classroom1.setId(nullptr);
    classroom1.setName(nullptr);
    userfile writeuser;
    writeuser.writeToFile(path, this, u1, classroom1);
}

// log in realization
void MainWindow::on_LogIn_clicked()
{
    QString path = "D:/Study/Term 2/OOOP/project/study_project/studyProject/user.json";
    userfile readuser;
    readuser.readFromFile(path, this, ui->Id->text(),ui->Password->text());
}

