#ifndef ANSWER_H
#define ANSWER_H
#include "question.h"
#include <QString>

class Answer:public Question
{
private:
    QString questionText;
    QString correctAns;
public:
    Answer();
    Answer(QString,QString);

    QString getAnsText(){
        return this->questionText;
    }
    void setTestText(QString text){
         this->questionText=text;
    }

    QString getCorrect(){
        return this->correctAns;
    }
    void setCorrect(QString corr){
         this->correctAns=corr;
    }
};

#endif // ANSWER_H
