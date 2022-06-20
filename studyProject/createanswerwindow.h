#ifndef CREATEANSWERWINDOW_H
#define CREATEANSWERWINDOW_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

namespace Ui {
class createanswerwindow;
}

class createanswerwindow : public QWidget
{
    Q_OBJECT

public:
    explicit createanswerwindow(QString nameOfTask,QWidget *parent = nullptr);
    std::vector<QString> ans;
    ~createanswerwindow();

private slots:
    void on_endTask_clicked();

private:
    Ui::createanswerwindow *ui;
};

#endif // CREATEANSWERWINDOW_H
