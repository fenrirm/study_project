#ifndef USER_H
#define USER_H
#include <QString>
#include <QLineEdit>
class user
{
private:
    QString NameLine;
    QString SurnameLine;
    QString IdLine;
    QString IsTeacher;
    QString Password;
public:
    user(QString nameLine, QString surnameLine, QString idLine, QString isTeacher, QString password );
    void setId(QString id);
    QString getId();
    void setIsTeacher(QString isTeacher);
    QString getIsTeacher();
    void setName(QString name);
    QString getName();
    void setSurname(QString surname);
    QString getSurname();
    void setPassword(QString password);
    QString getPassword();
//    friend QDataStream &operator>>(QDataStream &in, user &t);
//    friend QDataStream &operator<<(QDataStream &out, user &t);

};

#endif // USER_H
