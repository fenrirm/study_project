#include "ansfactory.h"
#include "questionfactory.h"

AnsFactory::AnsFactory()
{

}
Question* AnsFactory::createQuestion(QString text,QString ans){
    Answer* ansTask = new Answer(text,ans);
    return ansTask;
}
