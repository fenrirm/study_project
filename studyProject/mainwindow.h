#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void createJson(const QString &path);
    void readJson(const QString &path);
    bool cheackUnic(const QString &path,QString IDtoCheck);
    ~MainWindow();

private slots:
    void on_signup_clicked();
    void on_LogIn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
