#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "teacher.h"
#include "classroom.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>



TeacherWindow::TeacherWindow(QString name, QString surname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    ui->name->setText(name);
    ui->surname->setText(surname);
    ui->idClassLine->setPlaceholderText("Enter an id of a class");
    ui->nameClassLine->setPlaceholderText("Enter a name of a class");
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::createJson(const QString &path)

{

//    if(ui->Teacher->isChecked())
//    {
//        flag="true";
//    }
//    else
//    {
//        flag="false";
//    }

    Classroom classroom(ui->idClassLine->text(), ui->nameClassLine->text());

    classroom.setId(ui->idClassLine->text());
    classroom.setName(ui->nameClassLine->text());

    QJsonObject classroom1;
    QJsonObject obj;
    obj.insert("id", classroom.getId());
    obj.insert("name", classroom.getName());

    classroom1.insert(classroom.getId(), obj);
    bool unic = TeacherWindow::cheackUnic(path,classroom.getId());
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
                if(obj.keys()[0]==ui->idClassLine->text())
                    unic=false;
            }
        }
        arr.push_back(classroom1);
        QJsonDocument doc2(arr);
        QFile file (path);
        if(unic){
                    if(file.open(QIODevice::WriteOnly))
                    {
                        file.write(doc2.toJson());
                        QMessageBox::about(this,"","You have succesfully created the classroom");
                        file.close();
                    }
                    else
                    {
                        QMessageBox::critical(this,"","file opened failed: ");
                    }
                }else{
                    QMessageBox::critical(this,"","The classroon with the same id is already exist!");
                }

}
}

bool TeacherWindow::cheackUnic(const QString &path,QString IDtoCheck)
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

void TeacherWindow::on_createClass_clicked()
{
//   Classroom classroom(ui->idClassLine->text(), ui->nameClassLine->text());

//   classroom.setId(ui->idClassLine->text());
//   classroom.setName(ui->nameClassLine->text());
    QString path="D:/oop/Qt/studyProject/classroom.json";
    createJson(path);
}

