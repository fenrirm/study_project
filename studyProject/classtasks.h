#ifndef CLASSTASKS_H
#define CLASSTASKS_H

#include <QWidget>

namespace Ui {
class classTasks;
}

class classTasks : public QWidget
{
    Q_OBJECT

public:
    explicit classTasks(QWidget *parent = nullptr);
    ~classTasks();

private:
    Ui::classTasks *ui;
};

#endif // CLASSTASKS_H
