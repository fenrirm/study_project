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
    bool Is_Teacher;
    QString Password;
public:
    user(QString nameLine, QString surnameLine, QString idLine,bool is_Teacher, QString password );
    user();
    void setId(QString id);
    QString getId();
    void setName(QString name);
    QString getName();
    void setSurname(QString surname);
    QString getSurname();
    void setIs_Teacher(bool is_Teacher);
    bool getIs_Teacher();
    void setPassword(QString password);
    QString getPassword();
};

#endif // USER_H
