#ifndef CREATETESTWINDOW_H
#define CREATETESTWINDOW_H
#include <QWidget>
#include "vector"
#include "abstask.h"

namespace Ui {
class createTestWindow;
}

class createTestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit createTestWindow(QString testName, QWidget *parent = nullptr);
    QString teacherId;
    QString classroomName;
    bool checkUnic(const QString &path,QString NametoCheck);
    void writeToFile(QString& path,  createTestWindow* teastwindow, std::vector<AbsTask*>& questions);
    ~createTestWindow();

private slots:


    void on_createTest_clicked();

private:
    Ui::createTestWindow *ui;
};

#endif // CREATETESTWINDOW_H
