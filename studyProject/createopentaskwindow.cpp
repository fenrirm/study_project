#include "createopentaskwindow.h"
#include "ui_createopentaskwindow.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include "taskfactory.h"
#include "opentaskfactory.h"

createOpenTaskWindow::createOpenTaskWindow(QString opentaskname, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createOpenTaskWindow)
{
    ui->setupUi(this);
    ui->openTaskName->setText(opentaskname);
}

createOpenTaskWindow::~createOpenTaskWindow()
{
    delete ui;
}

bool createOpenTaskWindow::checkUnic(const QString &path,QString NametoCheck)
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
            if(obj.keys()[0] == NametoCheck)
            {
                return false;
            }
        }

    }
    return true;
}

void createOpenTaskWindow::writeToFile(QString& path,  createOpenTaskWindow* testwindow,  std::vector<AbsTask*>& questions)
{
    QJsonObject obj;
    bool unic = checkUnic(path,ui->openTaskName->text());
    obj.insert("teacheID", teacherId);
    obj.insert("clasroomName",classroomName);
    for (int i=0; i<questions.size(); i++)
    {
        QJsonObject opentask1;
        opentask1.insert("questionText",questions[i]->getTestText());
        opentask1.insert("rightanswer", questions[i]->getCorrect());
        obj.insert("question"+QString::number(i),  opentask1);
    }

    QJsonObject testobj;
    testobj.insert(ui->openTaskName->text(), obj);

    QFile f(path);
    if(f.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = f.readAll();
        f.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr = doc.array();
       arr.push_back(testobj);
       QJsonDocument doc2(arr);
       QFile file (path);
       if(unic)
       {
           if(file.open(QIODevice::WriteOnly))
           {
               file.write(doc2.toJson());
               QMessageBox::about(testwindow,"","You have succesfully created the task!");
               file.close();
           }
           else
           {
               QMessageBox::critical(testwindow,"","file opened failed: ");
           }
       }else
       {
           QMessageBox::critical(testwindow,"","The task with the same name is already exists!");
       }
    }
}

void createOpenTaskWindow::on_createOpenTask_clicked()
{
    std::vector<AbsTask*> questions;
    TaskFactory* creator = new OpenTaskFactory();
    AbsTask* opentask1 = creator->create();
    opentask1->setTestText(ui->question1->text());
    opentask1->setCorrect(ui->rightanswer1->text());
    questions.push_back(opentask1);
    AbsTask* opentask2 = creator->create();
    opentask2->setTestText(ui->question2->text());
    opentask2->setCorrect(ui->rightanswer2->text());
    questions.push_back(opentask2);
    AbsTask* opentask3 = creator->create();
    opentask3->setTestText(ui->question3->text());
    opentask3->setCorrect(ui->rightanswer3->text());
    questions.push_back(opentask3);
    AbsTask* opentask4 = creator->create();
    opentask4->setTestText(ui->question4->text());
    opentask4->setCorrect(ui->rightanswer4->text());
    questions.push_back(opentask4);
    AbsTask* opentask5 = creator->create();
    opentask5->setTestText(ui->question5->text());
    opentask5->setCorrect(ui->rightanswer5->text());
    questions.push_back(opentask5);
    AbsTask* opentask6 = creator->create();
    opentask6->setTestText(ui->question6->text());
    opentask6->setCorrect(ui->rightanswer6->text());
    questions.push_back(opentask6);
    AbsTask* opentask7 = creator->create();
    opentask7->setTestText(ui->question7->text());
    opentask7->setCorrect(ui->rightanswer7->text());
    questions.push_back(opentask7);
    AbsTask* opentask8 = creator->create();
    opentask8->setTestText(ui->question8->text());
    opentask8->setCorrect(ui->rightanswer8->text());
    questions.push_back(opentask8);
    AbsTask* opentask9 = creator->create();
    opentask9->setTestText(ui->question9->text());
    opentask9->setCorrect(ui->rightanswer9->text());
    questions.push_back(opentask9);
    AbsTask* opentask10 = creator->create();
    opentask10->setTestText(ui->question10->text());
    opentask10->setCorrect(ui->rightanswer10->text());
    questions.push_back(opentask10);
    AbsTask* opentask11 = creator->create();
    opentask11->setTestText(ui->question11->text());
    opentask11->setCorrect(ui->rightanswer11->text());
    questions.push_back(opentask11);
    AbsTask* opentask12 = creator->create();
    opentask12->setTestText(ui->question12->text());
    opentask12->setCorrect(ui->rightanswer12->text());
    questions.push_back(opentask12);
    QString path = "D:/oop/Qt/studyProject/opentasks.json";
    writeToFile(path, this, questions);
    this->close();
}

