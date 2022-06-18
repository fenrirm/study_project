#ifndef TEST_H
#define TEST_H
#include "question.h"
#include <QString>

class Test:public Question
{
private:
    QString questionText;
    int numberOfCorrecr;
public:
    Test();
    Test(QString,int);


    QString getTestText(){
        return this->questionText;
    }
    void setTestText(QString text){
         this->questionText=text;
    }

    int getCorrect(){
        return this->numberOfCorrecr;
    }
    void setCorrect(int corr){
         this->numberOfCorrecr=corr;
    }
};

#endif // TEST_H
