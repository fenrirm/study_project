#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QString name, QString surname, QWidget *parent = nullptr);
    void createJson(const QString &path);
    void readJson(const QString &path);
    bool cheackUnic(const QString &path,QString IDtoCheck);
    ~TeacherWindow();

private slots:
    void on_createClass_clicked();

private:
    Ui::TeacherWindow *ui;
};

#endif // TEACHERWINDOW_H
