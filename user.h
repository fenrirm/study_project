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
    QString Id2Line;
    QString Password;
public:
    user(QString nameLine, QString surnameLine, QString idLine, QString id2Line, QString password );
    void setId(QString id);
    QString getId();
    void setSecondId(QString secondId);
    QString getSecondId();
    void setName(QString name);
    QString getName();
    void setSurname(QString surname);
    QString getSurname();
    void setPassword(QString password);
    QString getPassword();


};

#endif // USER_H
