#ifndef OPENTASKFACTORY_H
#define OPENTASKFACTORY_H
#include "taskfactory.h"
#include <QString>
#include "opentask.h"

class OpenTaskFactory: public TaskFactory
{
public:
    //OpenTaskFactory();
    AbsTask* create() override
    {
        return new OpenTask();
    }
};

#endif // OPENTASKFACTORY_H
