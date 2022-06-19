#ifndef ABSTASK_H
#define ABSTASK_H
#include <QString>

class AbsTask
{
private:
    QString questionText;
    QString correctAnswer;
    QString answers[4];
public:
    virtual void createTask()=0;
    virtual QString getTestText()=0;
    virtual void setTestText(QString text)=0;
    virtual QString getCorrect()=0;
    virtual void setCorrect(QString corr)=0;
    virtual void setAnswers(QString Answer1, QString Answer2, QString Answer3, QString Answer4)=0;
    virtual QString getAnswer(int numOfAnswer)=0;

};

#endif // ABSTASK_H
