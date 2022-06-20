#ifndef OPENTASK_H
#define OPENTASK_H
#include <QString>
#include "abstask.h"

class OpenTask: public AbsTask
{
private:
    QString questionText;
    QString correctAnswer;
    QString answers[4];
public:
    OpenTask();
    OpenTask(QString, QString);
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

      }
      QString getAnswer(int numOfAnswer)override
      {
          return 0;
      }
      void createTask() override
      {

      }
};

#endif // OPENTASK_H
