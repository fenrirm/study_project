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

void classroomfile::addStudent(QString& path, secondwindow* studentwindow, QString teacherId, QString name, QString studentId)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        for(int i=0; i<arr.size(); i++)
        {
            QJsonObject obj = arr[i].toObject();
            if(obj.keys()[0]==teacherId)
            {
                if(obj[obj.keys()[0]].toObject()["name"].toString()==name)
                {

                     QJsonObject obj2 = obj[obj.keys()[0]].toObject();
                     QJsonArray ids=obj2["studentsId"].toArray();
                     ids.push_back(studentId);
                     obj2["studentsId"]=ids;
                     obj[obj.keys()[0]] = obj2;
                     arr[i] = obj;
                     break;

                }
                else
                {
                    qDebug()<<"wrong classroom name";
                    break;

                }
            }
            else
            {
                qDebug()<<"wrong classroom id";

            }

        }
        QJsonDocument doc2(arr);
        if(file.open(QIODevice::WriteOnly))
        {
            file.write(doc2.toJson());
            file.close();
        }
        else
        {
            qDebug()<<"file opened failed";
        }
    }


}

void classroomfile::writeToFile(QString& path, MainWindow* mainwindow, TeacherWindow* teacherwindow, user u1, Classroom classroom1)
{
    QJsonObject classroom;
    QJsonObject obj;
    QJsonArray ids;
    ids.push_back(0);
    QString array[100];
    array[0]="";
    obj.insert("name",classroom1.getName());
    obj.insert("studentsId", ids);
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
               QMessageBox::about(teacherwindow,"","You have succesfully created the class!");
               file.close();
           }
           else
           {
               QMessageBox::critical(teacherwindow,"","file opened failed: ");
           }
       }else
       {
           QMessageBox::critical(teacherwindow,"","The class with the same name is already exists!");
       }
    }
}



