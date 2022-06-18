#ifndef CREATETASKWINDOW_H
#define CREATETASKWINDOW_H

#include <QWidget>

namespace Ui {
class CreateTaskWindow;
}

class CreateTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTaskWindow(QWidget *parent = nullptr);
    ~CreateTaskWindow();

private:
    Ui::CreateTaskWindow *ui;
};

#endif // CREATETASKWINDOW_H
