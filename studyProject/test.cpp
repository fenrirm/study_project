#include "test.h"

Test::Test()
{

}

Test::Test(QString QuestionText, QString CorrectAnswer, QString Answer1,
           QString Answer2, QString Answer3,QString Answer4)
{
    questionText=QuestionText;
    correctAnswer=CorrectAnswer;
    answers[0]=Answer1;
    answers[1]=Answer2;
    answers[2]=Answer3;
    answers[3]=Answer4;

}

