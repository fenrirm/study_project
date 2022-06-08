#ifndef TEACHER_H
#define TEACHER_H
#include <QString>
#include <QLineEdit>
#include "user.h"
#include <vector>

class Teacher: public user{
private:
    std::vector<int> studenstID;
public:
    void addStuden(int student_ID){
        this->studenstID.push_back(student_ID);
    }

};
#endif // TEACHER_H
