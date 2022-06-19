#ifndef TEST_H
#define TEST_H
#include <QString>
#include <QDebug>
#include "abstask.h"
#include "createtestwindow.h"

class Test: public AbsTask
{
private:
    QString questionText;
    QString correctAnswer;
    QString answers[4];
public:
    Test();
    Test(QString,QString, QString, QString, QString, QString);
    QString getTestText() override{
          return this->questionText;
      }
      void setTestText(QString text)override{
           this->questionText=text;
      }

      QString getCorrect()override{
          return this->correctAnswer;
      }
      void setCorrect(QString corr)override{
           this->correctAnswer=corr;
      }
      void setAnswers(QString Answer1, QString Answer2, QString Answer3, QString Answer4) override
      {
          answers[0]=Answer1;
          answers[1]=Answer2;
          answers[2]=Answer3;
          answers[3]=Answer4;
      }
      QString getAnswer(int numOfAnswer)override
      {
          return this->answers[numOfAnswer];
      }
      void createTask() override
      {

      }


};

#endif // TEST_H
