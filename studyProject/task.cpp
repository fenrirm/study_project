
#include <QString>
#include "task.h"


//Task::Task(QString taskType, QString teacherID){

//}
Task::Task(){

}
Task::Task(QString type,QString teacher,QString classroom,QString name){
    this->type=type;
    this->IDTeacher=teacher;
    this->ClassName=classroom;
    this->name=name;
}
QString Task::getType(){
    return this->type;
}
QString Task::getIDClass(){
    return this->ClassName;
}
QString Task::getIDTeacher(){
     return this->IDTeacher;
}


void Task::setType(QString taskType){
    this->type=taskType;
}
void Task::setClassName(QString classID){
    this->ClassName=classID;
}
void Task::setIDTeacher(QString teacherID){
    this->IDTeacher=teacherID;
}
void Task::pushQusetion(Question* question){
    this->questionList.push_back(question);
}
