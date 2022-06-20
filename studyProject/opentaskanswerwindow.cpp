#include "opentaskanswerwindow.h"
#include "ui_opentaskanswerwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

OpenTaskAnswerWindow::OpenTaskAnswerWindow(QString testname, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenTaskAnswerWindow)
{
    ui->setupUi(this);

    QFile file("D:/Study/Term 2/OOOP/project/study_project/studyProject/opentasks.json");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();

            if(obj.keys()[0] == testname){
               ui->opentaskName->setText(testname);

                ui->question1->setText(obj[obj.keys()[0]].toObject()["question0"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question0"].toObject()["rightanswer"].toString());

                ui->question2->setText(obj[obj.keys()[0]].toObject()["question1"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question1"].toObject()["rightanswer"].toString());

                ui->question3->setText(obj[obj.keys()[0]].toObject()["question2"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question2"].toObject()["rightanswer"].toString());

                ui->question4->setText(obj[obj.keys()[0]].toObject()["question3"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question3"].toObject()["rightanswer"].toString());

                ui->question5->setText(obj[obj.keys()[0]].toObject()["question4"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question4"].toObject()["rightanswer"].toString());

                ui->question6->setText(obj[obj.keys()[0]].toObject()["question5"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question5"].toObject()["rightanswer"].toString());

                ui->question7->setText(obj[obj.keys()[0]].toObject()["question6"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question6"].toObject()["rightanswer"].toString());

                ui->question8->setText(obj[obj.keys()[0]].toObject()["question7"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question7"].toObject()["rightanswer"].toString());

                ui->question9->setText(obj[obj.keys()[0]].toObject()["question8"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question8"].toObject()["rightanswer"].toString());

                ui->question10->setText(obj[obj.keys()[0]].toObject()["question9"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question9"].toObject()["rightanswer"].toString());

                ui->question11->setText(obj[obj.keys()[0]].toObject()["question10"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question10"].toObject()["rightanswer"].toString());

                ui->question12->setText(obj[obj.keys()[0]].toObject()["question11"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question11"].toObject()["rightanswer"].toString());



                for(int i=0;i<ans.size();i++){
                    qDebug()<<ans[i]<< " ";
                }
            }
        }
    }
}

OpenTaskAnswerWindow::~OpenTaskAnswerWindow()
{
    delete ui;
}

void OpenTaskAnswerWindow::on_endOpenTask_clicked()
{
    int mark=0;
    if(ans[0]==ui->answer1->text()){
        mark++;
    }
    if(ans[1]==ui->answer2->text()){
        mark++;
    }
    if(ans[2]==ui->answer3->text()){
        mark++;
    }
    if(ans[3]==ui->answer4->text()){
        mark++;
    }
    if(ans[4]==ui->answer5->text()){
        mark++;
    }
    if(ans[5]==ui->answer6->text()){
        mark++;
    }
    if(ans[6]==ui->answer7->text()){
        mark++;
    }
    if(ans[7]==ui->answer8->text()){
        mark++;
    }
    if(ans[8]==ui->answer9->text()){
        mark++;
    }
    if(ans[9]==ui->answer10->text()){
        mark++;
    }
    if(ans[10]==ui->answer11->text()){
        mark++;
    }
    if(ans[11]==ui->answer12->text()){
        mark++;
    }
    QString mark_str = QString::number(mark);

    QMessageBox::about(this,"MARK", mark_str);
    this->close();
}

