#ifndef TASK_H
#define TASK_H
#include <QString>
#include <vector>
#include "question.h"

class Task
{
private:
    QString type;
    QString name;
    QString ClassName;
    QString IDTeacher;
    std::vector<Question*> questionList;
    QString theoryLink;
public:
    Task();
    Task(QString,QString,QString,QString);

    QString getType();
    QString getIDClass();
    QString getIDTeacher();

    void setType(QString taskType);
    void setClassName(QString classID);
    void setIDTeacher(QString teacherID);
    void pushQusetion(Question*);
};

#endif // TASK_H
