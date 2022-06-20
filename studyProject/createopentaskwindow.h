#ifndef CREATEOPENTASKWINDOW_H
#define CREATEOPENTASKWINDOW_H

#include <QWidget>

namespace Ui {
class createOpenTaskWindow;
}

class createOpenTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit createOpenTaskWindow(QWidget *parent = nullptr);
    ~createOpenTaskWindow();

private:
    Ui::createOpenTaskWindow *ui;
};

#endif // CREATEOPENTASKWINDOW_H
