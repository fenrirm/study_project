#ifndef CREATETASKWINDOW_H
#define CREATETASKWINDOW_H

#include <QWidget>
#include "task.h"
#include "questionfactory.h"
#include "testfactory.h"

namespace Ui {
class CreateTaskWindow;
}

class CreateTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTaskWindow(Task task,QWidget *parent = nullptr);
    Task* task;
    ~CreateTaskWindow();

private slots:


    void on_createButton_clicked();

private:
    Ui::CreateTaskWindow *ui;
};

#endif // CREATETASKWINDOW_H
