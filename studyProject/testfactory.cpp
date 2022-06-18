#include "testfactory.h"
#include "questionfactory.h"

TestFactory::TestFactory()
{

}

Question* TestFactory::createQuestion(QString text,int ans){
    Test* testQues = new Test(text,ans);
    return testQues;
}
