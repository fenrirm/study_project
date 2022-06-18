#ifndef QUESTIONFACTORY_H
#define QUESTIONFACTORY_H
#include "question.h"
#include "test.h"
#include "answer.h"

class QuestionFactory
{
public:
    QuestionFactory();
    virtual Question* createQuestion(QString,QString)=0;
    virtual Question* createQuestion(QString,int)=0;
};

#endif // QUESTIONFACTORY_H
