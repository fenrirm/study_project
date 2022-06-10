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
#include "teacherwindow.h"
#include <QApplication>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText("Enter your name");
    ui->surnameLine->setPlaceholderText("Enter your surname");
    ui->idLine->setPlaceholderText("Enter your id");
    //ui->id2Line->setPlaceholderText("Are you a student or a teacher?");
    ui->passwordLine->setPlaceholderText("Enter a password ");
    ui->Id->setPlaceholderText("Enter your Id");
    ui->Password->setPlaceholderText("Enter your password");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createJson(const QString &path)

{
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
    //u1.setSecondId(ui->id2Line->text());
    u1.setPassword(ui->passwordLine->text());
    QJsonObject user1;
    QJsonObject obj;
    obj.insert("name", u1.getName());
    obj.insert("surname", u1.getSurname());
    obj.insert("post", u1.getIsTeacher());
    obj.insert("pass", u1.getPassword());

    user1.insert(u1.getId(), obj);
    bool unic = MainWindow::cheackUnic(path,u1.getId());
    QFile f(path);
    if(f.open(QIODevice::ReadOnly))
    {
        qDebug()<<"if1";
        QByteArray bytes = f.readAll();
        f.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr = doc.array();
        if(doc.isObject())
        {
            QJsonObject json = doc.object();
            foreach(const QString& key, json.keys())
            {
                QJsonValue value = json.value(key);
            }
        }
        arr.push_back(user1);
        QJsonDocument doc2(arr);
        QFile file (path);
        if(unic){
            if(file.open(QIODevice::WriteOnly))
            {
                file.write(doc2.toJson());
                QMessageBox::about(this,"about","You have succesfully signed up!");
                file.close();
            }
            else
            {
                QMessageBox::critical(this,"critical","file opened failed: ");
            }
        }else{
            QMessageBox::critical(this,"critical","The user with the same id is already exists!");
        }
}

}
void MainWindow::readJson(const QString &path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
//            qDebug()<<obj;

            if(obj.keys()[0]==ui->Id->text())
            {
                //if the studen
                if(obj[obj.keys()[0]].toObject()["pass"].toString()==ui->Password->text() && obj[obj.keys()[0]].toObject()["post"].toString()=="false")
                {
                    secondwindow* window = new secondwindow(obj[obj.keys()[0]].toObject()["name"].toString(),
                            obj[obj.keys()[0]].toObject()["surname"].toString());
                    qDebug()<<"You have succesfully logged in!";
                    window->show();
                    this->close();
                }
                //if the teacher
                else if(obj[obj.keys()[0]].toObject()["pass"].toString()==ui->Password->text() && obj[obj.keys()[0]].toObject()["post"].toString()=="true"){
                    TeacherWindow* window = new TeacherWindow(nullptr);
                    qDebug()<<"You have succesfully logged in!";
                    window->show();
                    this->close();
                }

            }
        }
    }
}

bool MainWindow::cheackUnic(const QString &path,QString IDtoCheck)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
//            qDebug()<<obj;

            if(obj.keys()[0] == IDtoCheck)
            {
                return false;
            }
        }

    }
    return true;
}



// sign up realization
void MainWindow::on_signup_clicked()
{
    QString path = "D:/Study/Term 2/OOOP/study_project/study_project/study_project/studyProject/user.json";
    createJson(path);

}

// log in realization
void MainWindow::on_LogIn_clicked()
{
    QString path = "D:/Study/Term 2/OOOP/study_project/study_project/study_project/studyProject/user.json";
    readJson(path);
//    QFile file;
//    file.setFileName("user.txt");
//    bool flag = true;
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        QTextStream readStream(&file);
//        while(!readStream.atEnd() )
//        {
//            QString line, line2;
//            readStream >> line;
//            if(line==ui->Id->text())
//            {
//                readStream>>line2;
//                if(line2==ui->Password->text())
//                {
//                    qDebug()<<"You have succesfully logged in!";
//                                   qDebug()<<"You've succesfully authorized!";
//                                    window->show();
//                                   this->close();
//                    flag = false;
//                    break;
//                }

//            }

//        }
//            if (flag)
//        {
//            qDebug()<<"You have entered wrong login or this user doesn't exist!";
//        }

//    }
//    file.close();

}

