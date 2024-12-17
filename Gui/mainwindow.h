#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QPushButton>
#include <QDateTimeEdit>
#include "appointmentservice.h"
#include "customerservice.h"
#include "servicesservice.h"
#include "noteservice.h"


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
    void showTablePopup();
    void onSaveCompleted();
    void on_pushButton_2_clicked();
    void onAppointmentsButtonClicked();
    void onServicesButtonClicked();
    void onLoginClicked();
    void onCreateAccountClicked();
    void onContactUsButtonClicked();
    void onInvoicesButtonClicked();

private:
    Ui::MainWindow *ui;
    void loadCustomers();
    std::shared_ptr<AppointmentService> appointmentService;
    std::shared_ptr<CustomerService> customerService;
    std::shared_ptr<ServicesService> servicesService;
    std::shared_ptr<NotesService> notesService;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *createAccountButton;
    QPushButton *loginButton;
};
#endif // MAINWINDOW_H
