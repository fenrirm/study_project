#ifndef TESTFACTORY_H
#define TESTFACTORY_H
#include "taskfactory.h"
#include "test.h"
#include <QString>
class TestFactory: public TaskFactory
{
public:
    //TestFactory();
    AbsTask* create() override
    {
        return new Test();
    }

};

#endif // TESTFACTORY_H
