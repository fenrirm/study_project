#include "testfactory.h"
#include "questionfactory.h"

Question* TestFactory::createQuestion(QString text,int ans){
    Test* testQues = new Test(text,ans);
    return testQues;
}
