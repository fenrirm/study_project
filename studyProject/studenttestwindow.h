#ifndef STUDENTTESTWINDOW_H
#define STUDENTTESTWINDOW_H

#include <QWidget>

namespace Ui {
class studenttestwindow;
}

class studenttestwindow : public QWidget
{
    Q_OBJECT

public:
    explicit studenttestwindow(QWidget *parent = nullptr);
    ~studenttestwindow();

private:
    Ui::studenttestwindow *ui;
};

#endif // STUDENTTESTWINDOW_H
