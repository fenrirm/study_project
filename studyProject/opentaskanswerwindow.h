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
    explicit OpenTaskAnswerWindow(QString testname,QWidget *parent = nullptr);
    std::vector<QString> ans;
    ~OpenTaskAnswerWindow();

private slots:
    void on_endOpenTask_clicked();

private:
    Ui::OpenTaskAnswerWindow *ui;
};

#endif // OPENTASKANSWERWINDOW_H
