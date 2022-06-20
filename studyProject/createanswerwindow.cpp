#include "createanswerwindow.h"
#include "ui_createanswerwindow.h"
#include "QFile"
#include <QMessageBox>
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
                ui->taskName->setText(nameOfTask);

                ui->question1->setText(obj[obj.keys()[0]].toObject()["question0"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question0"].toObject()["rightanswer"].toString());
                ui->answer1_1->setText(obj[obj.keys()[0]].toObject()["question0"].toObject()["answers"].toArray()[0].toString());
                ui->answer1_2->setText(obj[obj.keys()[0]].toObject()["question0"].toObject()["answers"].toArray()[1].toString());
                ui->answer1_3->setText(obj[obj.keys()[0]].toObject()["question0"].toObject()["answers"].toArray()[2].toString());
                ui->answer1_4->setText(obj[obj.keys()[0]].toObject()["question0"].toObject()["answers"].toArray()[3].toString());

                ui->question2->setText(obj[obj.keys()[0]].toObject()["question1"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question1"].toObject()["rightanswer"].toString());
                ui->answer2_1->setText(obj[obj.keys()[0]].toObject()["question1"].toObject()["answers"].toArray()[0].toString());
                ui->answer2_2->setText(obj[obj.keys()[0]].toObject()["question1"].toObject()["answers"].toArray()[1].toString());
                ui->answer2_3->setText(obj[obj.keys()[0]].toObject()["question1"].toObject()["answers"].toArray()[2].toString());
                ui->answer2_4->setText(obj[obj.keys()[0]].toObject()["question1"].toObject()["answers"].toArray()[3].toString());

                ui->question3->setText(obj[obj.keys()[0]].toObject()["question2"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question2"].toObject()["rightanswer"].toString());
                ui->answer3_1->setText(obj[obj.keys()[0]].toObject()["question2"].toObject()["answers"].toArray()[0].toString());
                ui->answer3_2->setText(obj[obj.keys()[0]].toObject()["question2"].toObject()["answers"].toArray()[1].toString());
                ui->answer3_3->setText(obj[obj.keys()[0]].toObject()["question2"].toObject()["answers"].toArray()[2].toString());
                ui->answer3_4->setText(obj[obj.keys()[0]].toObject()["question2"].toObject()["answers"].toArray()[3].toString());

                ui->question4->setText(obj[obj.keys()[0]].toObject()["question3"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question3"].toObject()["rightanswer"].toString());
                ui->answer4_1->setText(obj[obj.keys()[0]].toObject()["question3"].toObject()["answers"].toArray()[0].toString());
                ui->answer4_2->setText(obj[obj.keys()[0]].toObject()["question3"].toObject()["answers"].toArray()[1].toString());
                ui->answer4_3->setText(obj[obj.keys()[0]].toObject()["question3"].toObject()["answers"].toArray()[2].toString());
                ui->answer4_4->setText(obj[obj.keys()[0]].toObject()["question3"].toObject()["answers"].toArray()[3].toString());

                ui->question5->setText(obj[obj.keys()[0]].toObject()["question4"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question4"].toObject()["rightanswer"].toString());
                ui->answer5_1->setText(obj[obj.keys()[0]].toObject()["question4"].toObject()["answers"].toArray()[0].toString());
                ui->answer5_2->setText(obj[obj.keys()[0]].toObject()["question4"].toObject()["answers"].toArray()[1].toString());
                ui->answer5_3->setText(obj[obj.keys()[0]].toObject()["question4"].toObject()["answers"].toArray()[2].toString());
                ui->answer5_4->setText(obj[obj.keys()[0]].toObject()["question4"].toObject()["answers"].toArray()[3].toString());

                ui->question6->setText(obj[obj.keys()[0]].toObject()["question5"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question5"].toObject()["rightanswer"].toString());
                ui->answer6_1->setText(obj[obj.keys()[0]].toObject()["question5"].toObject()["answers"].toArray()[0].toString());
                ui->answer6_2->setText(obj[obj.keys()[0]].toObject()["question5"].toObject()["answers"].toArray()[1].toString());
                ui->answer6_3->setText(obj[obj.keys()[0]].toObject()["question5"].toObject()["answers"].toArray()[2].toString());
                ui->answer6_4->setText(obj[obj.keys()[0]].toObject()["question5"].toObject()["answers"].toArray()[3].toString());

                ui->question7->setText(obj[obj.keys()[0]].toObject()["question6"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question6"].toObject()["rightanswer"].toString());
                ui->answer7_1->setText(obj[obj.keys()[0]].toObject()["question6"].toObject()["answers"].toArray()[0].toString());
                ui->answer7_2->setText(obj[obj.keys()[0]].toObject()["question6"].toObject()["answers"].toArray()[1].toString());
                ui->answer7_3->setText(obj[obj.keys()[0]].toObject()["question6"].toObject()["answers"].toArray()[2].toString());
                ui->answer7_4->setText(obj[obj.keys()[0]].toObject()["question6"].toObject()["answers"].toArray()[3].toString());

                ui->question8->setText(obj[obj.keys()[0]].toObject()["question7"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question7"].toObject()["rightanswer"].toString());
                ui->answer8_1->setText(obj[obj.keys()[0]].toObject()["question7"].toObject()["answers"].toArray()[0].toString());
                ui->answer8_2->setText(obj[obj.keys()[0]].toObject()["question7"].toObject()["answers"].toArray()[1].toString());
                ui->answer8_3->setText(obj[obj.keys()[0]].toObject()["question7"].toObject()["answers"].toArray()[2].toString());
                ui->answer8_4->setText(obj[obj.keys()[0]].toObject()["question7"].toObject()["answers"].toArray()[3].toString());

                ui->question9->setText(obj[obj.keys()[0]].toObject()["question8"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question8"].toObject()["rightanswer"].toString());
                ui->answer9_1->setText(obj[obj.keys()[0]].toObject()["question8"].toObject()["answers"].toArray()[0].toString());
                ui->answer9_2->setText(obj[obj.keys()[0]].toObject()["question8"].toObject()["answers"].toArray()[1].toString());
                ui->answer9_3->setText(obj[obj.keys()[0]].toObject()["question8"].toObject()["answers"].toArray()[2].toString());
                ui->answer9_4->setText(obj[obj.keys()[0]].toObject()["question8"].toObject()["answers"].toArray()[3].toString());

                ui->question10->setText(obj[obj.keys()[0]].toObject()["question9"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question9"].toObject()["rightanswer"].toString());
                ui->answer10_1->setText(obj[obj.keys()[0]].toObject()["question9"].toObject()["answers"].toArray()[0].toString());
                ui->answer10_2->setText(obj[obj.keys()[0]].toObject()["question9"].toObject()["answers"].toArray()[1].toString());
                ui->answer10_3->setText(obj[obj.keys()[0]].toObject()["question9"].toObject()["answers"].toArray()[2].toString());
                ui->answer10_4->setText(obj[obj.keys()[0]].toObject()["question9"].toObject()["answers"].toArray()[3].toString());

                ui->question11->setText(obj[obj.keys()[0]].toObject()["question10"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question10"].toObject()["rightanswer"].toString());
                ui->answer11_1->setText(obj[obj.keys()[0]].toObject()["question10"].toObject()["answers"].toArray()[0].toString());
                ui->answer11_2->setText(obj[obj.keys()[0]].toObject()["question10"].toObject()["answers"].toArray()[1].toString());
                ui->answer11_3->setText(obj[obj.keys()[0]].toObject()["question10"].toObject()["answers"].toArray()[2].toString());
                ui->answer11_4->setText(obj[obj.keys()[0]].toObject()["question10"].toObject()["answers"].toArray()[3].toString());

                ui->question12->setText(obj[obj.keys()[0]].toObject()["question11"].toObject()["questionText"].toString());
                ans.push_back(obj[obj.keys()[0]].toObject()["question11"].toObject()["rightanswer"].toString());
                ui->answer12_1->setText(obj[obj.keys()[0]].toObject()["question11"].toObject()["answers"].toArray()[0].toString());
                ui->answer12_2->setText(obj[obj.keys()[0]].toObject()["question11"].toObject()["answers"].toArray()[1].toString());
                ui->answer12_3->setText(obj[obj.keys()[0]].toObject()["question11"].toObject()["answers"].toArray()[2].toString());
                ui->answer12_4->setText(obj[obj.keys()[0]].toObject()["question11"].toObject()["answers"].toArray()[3].toString());

                for(int i=0;i<ans.size();i++){
                    qDebug()<<ans[i]<< " ";
                }
            }
        }
    }
}

createanswerwindow::~createanswerwindow()
{
    delete ui;
}

void createanswerwindow::on_endTask_clicked()
{
    int mark=0;
    if(ans[0]==ui->rightanswer1->text()){
        mark++;
    }
    if(ans[1]==ui->rightanswer2->text()){
        mark++;
    }
    if(ans[2]==ui->rightanswer3->text()){
        mark++;
    }
    if(ans[3]==ui->rightanswer4->text()){
        mark++;
    }
    if(ans[4]==ui->rightanswer5->text()){
        mark++;
    }
    if(ans[5]==ui->rightanswer6->text()){
        mark++;
    }
    if(ans[6]==ui->rightanswer7->text()){
        mark++;
    }
    if(ans[7]==ui->rightanswer8->text()){
        mark++;
    }
    if(ans[8]==ui->rightanswer9->text()){
        mark++;
    }
    if(ans[9]==ui->rightanswer10->text()){
        mark++;
    }
    if(ans[10]==ui->rightanswer11->text()){
        mark++;
    }
    if(ans[11]==ui->rightanswer12->text()){
        mark++;
    }
    QString mark_str = QString::number(mark);

    QMessageBox::about(this,"MARK", mark_str);
    this->close();
}

