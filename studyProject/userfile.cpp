#include "userfile.h"

userfile::userfile()
{

}

bool userfile::checkUnic(const QString &path,QString IDtoCheck)
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
            if(obj.keys()[0] == IDtoCheck)
            {
                return false;
            }
        }

    }
    return true;
}
void userfile::writeToFile(QString& path,  MainWindow* mainwindow, user u1, Classroom classroom1)
{
    QJsonObject user1;
    QJsonObject obj;
    obj.insert("name", u1.getName());
    obj.insert("surname", u1.getSurname());
    obj.insert("post", u1.getIsTeacher());
    obj.insert("pass", u1.getPassword());
    user1.insert(u1.getId(), obj);
    bool unic = checkUnic(path,u1.getId());
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
       arr.push_back(user1);
       QJsonDocument doc2(arr);
       QFile file (path);
       if(unic)
       {
           if(file.open(QIODevice::WriteOnly))
           {
               file.write(doc2.toJson());
               QMessageBox::about(mainwindow,"","You have succesfully signed up!");
               file.close();
           }
           else
           {
               QMessageBox::critical(mainwindow,"","file opened failed: ");
           }
       }else
       {
           QMessageBox::critical(mainwindow,"","The user with the same id is already exists!");
       }
    }
}


void userfile::readFromFile(QString& path,  MainWindow* mainwindow, QString id, QString pass)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        secondwindow* window;
        TeacherWindow* window2;
        QByteArray bytes = file.readAll();
        file.close();
        QJsonDocument doc (QJsonDocument::fromJson(bytes));
        QJsonArray arr= doc.array();
        foreach(const QJsonValue& value, arr)
        {
            QJsonObject obj = value.toObject();
            if(obj.keys()[0]==id)
            {
                if(obj[obj.keys()[0]].toObject()["pass"].toString()==pass)
                {
                    if( obj[obj.keys()[0]].toObject()["post"].toString()=="false")
                    {
                        window = new secondwindow(obj.keys()[0],
                                obj[obj.keys()[0]].toObject()["name"].toString(),
                        obj[obj.keys()[0]].toObject()["surname"].toString());
                        QMessageBox::about(mainwindow, "", "You have succesfully logged in");
                        window->show();
                        mainwindow->close();
                        file.close();
                        return;
                    }
                    else
                    {
                        window2= new TeacherWindow(obj.keys()[0],
                                obj[obj.keys()[0]].toObject()["name"].toString(),
                        obj[obj.keys()[0]].toObject()["surname"].toString());
                        QMessageBox::about(mainwindow, "", "You nave succesfully logged in");
                        window2->show();
                        mainwindow->close();
                        file.close();
                        return;
                    }
                    delete window2;
                }

                else
                {
                    QMessageBox::critical(mainwindow, "", "You have entered wrong password!");
                    return;
                }
            }
            delete window;

        }
        QMessageBox::critical(mainwindow, "", "This user doesn't exist or you've entered wrong id");

    }
}
