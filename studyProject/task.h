#ifndef TASK_H
#define TASK_H
#include <QString>
#include <vector>
class Task
{
private:
    QString type;
    QString IDClass;
    QString IDTeacher;

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
