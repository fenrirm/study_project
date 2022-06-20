#include "ansfactory.h"
#include "questionfactory.h"

AnsFactory::AnsFactory()
{

}
Question AnsFactory::createQuestion(QString text,QString ans){
    Answer ansTask;
    ansTask.setQuestionText(text);
    ansTask.setCorrect(ans);
    return ansTask;
}
