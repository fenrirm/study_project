#ifndef CREATEOPENTASKWINDOW_H
#define CREATEOPENTASKWINDOW_H
#include <QWidget>
#include "vector"
#include "abstask.h"


namespace Ui {
class createOpenTaskWindow;
}

class createOpenTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit createOpenTaskWindow(QString opentaskname, QWidget *parent = nullptr);
    QString teacherId;
    QString classroomName;
    bool checkUnic(const QString &path,QString NametoCheck);
    void writeToFile(QString& path,  createOpenTaskWindow* teastwindow, std::vector<AbsTask*>& questions);
    ~createOpenTaskWindow();


private slots:
    void on_createOpenTask_clicked();

private:
    Ui::createOpenTaskWindow *ui;
};

#endif // CREATEOPENTASKWINDOW_H
