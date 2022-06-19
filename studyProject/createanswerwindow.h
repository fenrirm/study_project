#ifndef CREATEANSWERWINDOW_H
#define CREATEANSWERWINDOW_H

#include <QWidget>

namespace Ui {
class createanswerwindow;
}

class createanswerwindow : public QWidget
{
    Q_OBJECT

public:
    explicit createanswerwindow(QWidget *parent = nullptr);
    ~createanswerwindow();

private:
    Ui::createanswerwindow *ui;
};

#endif // CREATEANSWERWINDOW_H
