#include "createanswerwindow.h"
#include "ui_createanswerwindow.h"
#include "QFile"

createanswerwindow::createanswerwindow(QString nameOfTask,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createanswerwindow)
{
    ui->setupUi(this);

    QFile file("D:/Study/Term 2/OOOP/project/study_project/studyProject/tests.json");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            qDebug()<<obj.keys()[0]<<" == "<<nameOfTask;
            if(obj.keys()[0] == nameOfTask){
                std::vector<QString> ans;
                ui->taskName->setText(nameOfTask);

                ui->question1->setText(obj[obj.keys()[0]].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["rightanswer"].toString());
                qDebug()<<obj[obj.keys()[0]].toObject()["question0"].toArray()[0].toString()<<" "<<obj[obj.keys()[0]].toObject()["question0"].toArray()[3].toString();
                ui->answer1_1->setText(obj[obj.keys()[0]].toObject()["question0"].toArray()[0].toString());
                ui->answer1_2->setText(obj[obj.keys()[0]].toObject()["question0"].toArray()[1].toString());
                ui->answer1_3->setText(obj[obj.keys()[0]].toObject()["question0"].toArray()[2].toString());
                ui->answer1_4->setText(obj[obj.keys()[0]].toObject()["question0"].toArray()[3].toString());

            }
        }
    }
}

createanswerwindow::~createanswerwindow()
{
    delete ui;
}
