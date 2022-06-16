
#include <QString>
#include "task.h"


//Task::Task(QString taskType, QString teacherID){

//}
Task::Task(){

}
QString Task::getType(){
    return this->type;
}
QString Task::getIDClass(){
    return this->IDClass;
}
QString Task::getIDTeacher(){
     return this->IDTeacher;
}


void Task::setType(QString taskType){
    this->type=taskType;
}
void Task::setIDClass(QString classID){
    this->IDClass=classID;
}
void Task::setIDTeacher(QString teacherID){
    this->IDTeacher=teacherID;
}
