#ifndef ANSFACTORY_H
#define ANSFACTORY_H

#include "questionfactory.h"
#include "question.h"
#include "test.h"
#include "answer.h"


class AnsFactory:public QuestionFactory
{
public:
    AnsFactory();
    Question* createQuestion(QString,QString) override;
};

#endif // ANSFACTORY_H
