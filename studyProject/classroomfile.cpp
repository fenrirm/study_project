#include "classroomfile.h"

classroomfile::classroomfile()
{

}

bool classroomfile::checkUnic(const QString &path,QString nameToCheck)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            if(obj[obj.keys()[0]].toObject()["name"].toString() == nameToCheck)
            {
                return false;
            }
        }

    }
    return true;
}
void classroomfile::writeToFile(QString& path,  TeacherWindow* mainwindow, user u1, Classroom classroom1)
{
    QJsonObject classroom;
    QJsonObject obj;
    obj.insert("name",classroom1.getName());
    classroom.insert(classroom1.getId(), obj);
    bool unic = checkUnic(path,classroom1.getName());
    QFile f(path);
    if(f.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = f.readAll();
        f.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr = doc.array();
       if(doc.isObject())
       {
           QJsonObject json = doc.object();
           foreach(const QString& key, json.keys())
           {
               QJsonValue value = json.value(key);
           }
       }
       arr.push_back(classroom);
       QJsonDocument doc2(arr);
       QFile file (path);
       if(unic)
       {
           if(file.open(QIODevice::WriteOnly))
           {
               file.write(doc2.toJson());
               QMessageBox::about(mainwindow,"","You have succesfully created the class!");
               file.close();
           }
           else
           {
               QMessageBox::critical(mainwindow,"","file opened failed: ");
           }
       }else
       {
           QMessageBox::critical(mainwindow,"","The class with the same name is already exists!");
       }
    }
}


