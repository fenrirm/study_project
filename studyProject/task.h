#ifndef TASK_H
#define TASK_H
#include <QString>
#include <vector>
#include "question.h"

class Task
{
private:
    QString type;
    QString IDClass;
    QString IDTeacher;
    std::vector<Question> questionList;
public:
    Task();

    QString getType();
    QString getIDClass();
    QString getIDTeacher();

    void setType(QString taskType);
    void setIDClass(QString classID);
    void setIDTeacher(QString teacherID);
};

#endif // TASK_H
