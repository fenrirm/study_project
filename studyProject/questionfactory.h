#ifndef QUESTIONFACTORY_H
#define QUESTIONFACTORY_H
#include "abstask.h"

class QuestionFactory
{
public:
    QuestionFactory();
    virtual AbsTask* create()=0;
};

#endif // QUESTIONFACTORY_H
