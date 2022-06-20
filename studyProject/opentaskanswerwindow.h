#ifndef OPENTASKANSWERWINDOW_H
#define OPENTASKANSWERWINDOW_H

#include <QWidget>

namespace Ui {
class OpenTaskAnswerWindow;
}

class OpenTaskAnswerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OpenTaskAnswerWindow(QWidget *parent = nullptr);
    ~OpenTaskAnswerWindow();

private:
    Ui::OpenTaskAnswerWindow *ui;
};

#endif // OPENTASKANSWERWINDOW_H
