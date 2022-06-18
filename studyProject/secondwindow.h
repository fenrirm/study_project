#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#pragma once
#include <QMainWindow>

namespace Ui {
class secondwindow;
}

class secondwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit secondwindow(QString id, QString name, QString surname, QWidget *parent = nullptr);
    ~secondwindow();

private slots:


    void on_connectToClass_clicked();

    void on_logOut_clicked();

private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
