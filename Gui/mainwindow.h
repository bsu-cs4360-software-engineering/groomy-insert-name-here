#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD

#include <QMainWindow>
=======
#include <QMainWindow>
#include <QDateTimeEdit>
>>>>>>> workspace-Lucas

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();
    void on_Login_clicked();
    void showTablePopup();
    void onSaveCompleted();
<<<<<<< HEAD
=======
    void on_pushButton_2_clicked();
>>>>>>> workspace-Lucas

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
