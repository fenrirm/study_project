#ifndef TASKFACTORY_H
#define TASKFACTORY_H
#include "abstask.h"

class TaskFactory
{
public:
    TaskFactory();
    virtual AbsTask* create()=0;
};

#endif // TASKFACTORY_H
