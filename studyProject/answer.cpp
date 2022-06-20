#include "answer.h"


Answer::Answer()
{

}

Answer::Answer(QString quest,QString ans)
{
    this->questionText=quest;
    this->correctAns=ans;
}

