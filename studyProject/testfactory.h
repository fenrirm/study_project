#ifndef TESTFACTORY_H
#define TESTFACTORY_H

#include "questionfactory.h"
#include "question.h"
#include "test.h"
#include "answer.h"

class TestFactory:public QuestionFactory
{
public:
    TestFactory();
    Question* createQuestion(QString,int) override;
};

#endif // TESTFACTORY_H
