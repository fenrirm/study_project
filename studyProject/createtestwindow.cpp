#include "ui_createtestwindow.h"
#include "taskfactory.h"
#include "testfactory.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

createTestWindow::createTestWindow(QString testname, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createTestWindow)
{
    ui->setupUi(this);
    ui->testName->setText(testname);

}

createTestWindow::~createTestWindow()
{
    delete ui;
}

bool createTestWindow::checkUnic(const QString &path,QString NametoCheck)
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
void createTestWindow::writeToFile(QString& path,  createTestWindow* testwindow,  std::vector<AbsTask*>& questions)
{
    QJsonObject obj;
    bool unic = checkUnic(path,ui->testName->text());
    obj.insert("teacheID", teacherId);
    obj.insert("clasroomName",classroomName);
    for (int i=0; i<questions.size(); i++)
    {
        QJsonObject test1;
        test1.insert("questionText",questions[i]->getTestText());
        QJsonArray answers;
        answers.push_back(questions[i]->getAnswer(0));
        answers.push_back(questions[i]->getAnswer(1));
        answers.push_back(questions[i]->getAnswer(2));
        answers.push_back(questions[i]->getAnswer(3));
        test1.insert("answers", answers);
        test1.insert("rightanswer", questions[i]->getCorrect());
        obj.insert("question"+QString::number(i), test1);
    }
    qDebug()<<questions.size();
    QJsonObject testobj;
    testobj.insert(ui->testName->text(), obj);

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
               QMessageBox::about(testwindow,"","You have succesfully signed up!");
               file.close();
           }
           else
           {
               QMessageBox::critical(testwindow,"","file opened failed: ");
           }
       }else
       {
           QMessageBox::critical(testwindow,"","The user with the same id is already exists!");
       }
    }
}

void createTestWindow::on_createTest_clicked()
{
    std::vector<AbsTask*> questions;
    TaskFactory* creator = new TestFactory();
    AbsTask* test1 = creator->create();
    test1->setTestText(ui->question1->text());
    test1->setAnswers(ui->answer1_1->text(),ui->answer1_2->text(),ui->answer1_2->text(),ui->answer1_2->text());
    test1->setCorrect(ui->rightanswer1->text());
    questions.push_back(test1);
    AbsTask* test2 = creator->create();
    test2->setTestText(ui->question2->text());
    test2->setAnswers(ui->answer2_1->text(),ui->answer2_2->text(),ui->answer2_3->text(),ui->answer2_4->text());
    test2->setCorrect(ui->rightanswer2->text());
    questions.push_back(test2);
    AbsTask* test3 = creator->create();
    test3->setTestText(ui->question3->text());
    test3->setAnswers(ui->answer3_1->text(),ui->answer3_2->text(),ui->answer3_3->text(),ui->answer3_4->text());
    test3->setCorrect(ui->rightanswer3->text());
    questions.push_back(test3);
    AbsTask* test4 = creator->create();
    test4->setTestText(ui->question4->text());
    test4->setAnswers(ui->answer4_1->text(),ui->answer4_2->text(),ui->answer4_3->text(),ui->answer4_4->text());
    test4->setCorrect(ui->rightanswer4->text());
    questions.push_back(test4);
    AbsTask* test5 = creator->create();
    test5->setTestText(ui->question5->text());
    test5->setAnswers(ui->answer5_1->text(),ui->answer5_2->text(),ui->answer5_3->text(),ui->answer5_4->text());
    test5->setCorrect(ui->rightanswer5->text());
    questions.push_back(test5);
    AbsTask* test6 = creator->create();
    test6->setTestText(ui->question6->text());
    test6->setAnswers(ui->answer6_1->text(),ui->answer6_2->text(),ui->answer6_3->text(),ui->answer6_4->text());
    test6->setCorrect(ui->rightanswer6->text());
    questions.push_back(test6);
    AbsTask* test7 = creator->create();
    test7->setTestText(ui->question7->text());
    test7->setAnswers(ui->answer7_1->text(),ui->answer7_2->text(),ui->answer7_3->text(),ui->answer7_4->text());
    test7->setCorrect(ui->rightanswer7->text());
    questions.push_back(test7);
    AbsTask* test8 = creator->create();
    test8->setTestText(ui->question8->text());
    test8->setAnswers(ui->answer8_1->text(),ui->answer8_2->text(),ui->answer8_3->text(),ui->answer8_4->text());
    test8->setCorrect(ui->rightanswer8->text());
    questions.push_back(test8);
    AbsTask* test9 = creator->create();
    test9->setTestText(ui->question9->text());
    test9->setAnswers(ui->answer9_1->text(),ui->answer9_2->text(),ui->answer9_3->text(),ui->answer9_4->text());
    test9->setCorrect(ui->rightanswer9->text());
    questions.push_back(test9);
    AbsTask* test10 = creator->create();
    test10->setTestText(ui->question10->text());
    test10->setAnswers(ui->answer10_1->text(),ui->answer10_2->text(),ui->answer10_3->text(),ui->answer10_4->text());
    test10->setCorrect(ui->rightanswer10->text());
    questions.push_back(test10);
    AbsTask* test11 = creator->create();
    test11->setTestText(ui->question11->text());
    test11->setAnswers(ui->answer11_1->text(),ui->answer11_2->text(),ui->answer11_3->text(),ui->answer11_4->text());
    test11->setCorrect(ui->rightanswer11->text());
    questions.push_back(test11);
    AbsTask* test12 = creator->create();
    test12->setTestText(ui->question12->text());
    test12->setAnswers(ui->answer12_1->text(),ui->answer12_2->text(),ui->answer12_3->text(),ui->answer12_4->text());
    test12->setCorrect(ui->rightanswer12->text());
    questions.push_back(test12);
    QString path = "D:/oop/Qt/studyProject/tests.json";
    writeToFile(path, this, questions);
    this->close();

}
