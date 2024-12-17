#include "mainwindow.h"
#include "appointmentsdialog.h"
#include "ui_mainwindow.h"
#include "customerservice.h"
#include "appointmentservice.h"
#include "servicesservice.h"
#include "noteservice.h"
#include "servicesview.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include "tablepopup.h"
#include "customers.h"
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , appointmentService(new AppointmentService("appointments.json"))
    , customerService(new CustomerService("customers.json"))
    , servicesService(new ServicesService("services.json"))
    , notesService(std::make_shared<NotesService>("notes.json", "service_notes.json", "customer_notes.json", "appointment_notes.json"))


{
    ui->setupUi(this);
    QPixmap pix("C:/Users/lprit/OneDrive/Documents/Gui/images/user.png");
    ui->user->setPixmap(pix);
    QPixmap pix2("C:/Users/lprit/OneDrive/Documents/Gui/images/security.png");
    ui->security->setPixmap(pix2);
    QPixmap pix3("C:/Users/lprit/OneDrive/Documents/Gui/images/courage.png");
    ui->courage->setPixmap(pix3);
    connect(ui->appointments, &QPushButton::clicked, this, &MainWindow::onAppointmentsButtonClicked);
    connect(ui->services, &QPushButton::clicked, this, &MainWindow::onServicesButtonClicked);
    connect(ui->pushButtonCreateAccount, &QPushButton::clicked, this, &MainWindow::onCreateAccountClicked); // Connect pushButtonCreateAccount
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onContactUsButtonClicked);



    usernameEdit = ui->lineEditUsername; // Assuming you have a QLineEdit with objectName "lineEditUsername"
    passwordEdit = ui->lineEditPassword; // Assuming you have a QLineEdit with objectName "lineEditPassword" // Assuming you have a QPushButton with objectName "pushButtonCreateAccount"
    loginButton = ui->pushButtonLogin;


    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);

    // Check if ui, appointmentService, and customerService are properly initialized
    if (!ui) {
        qDebug() << "UI initialization failed";
        return;
    }
    if (!appointmentService) {
        qDebug() << "AppointmentService initialization failed";
        return;
    }
    if (!customerService) {
        qDebug() << "CustomerService initialization failed";
        return;
    }

    // Access the QDateTimeEdit widget directly
    if (ui->dateEdit) {
        // Set the current local date and time
        ui->dateEdit->setDateTime(QDateTime::currentDateTime());
        ui->dateEdit->setCalendarPopup(true);
    }


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::showTablePopup()
{
    TablePopup *dialog = new TablePopup(this);
    connect(dialog, &TablePopup::saveCompleted, this, &MainWindow::onSaveCompleted);
    dialog->exec();
}
void MainWindow::onSaveCompleted()
{
    // Handle the transition back to the main screen if needed
    // For example, you can show a specific widget or update the UI
    // In this case, we simply show a message box
    QMessageBox::information(this, "Info", "Returned to the main screen.");
    delete ui;
}


void MainWindow::onLoginClicked()
{
    QMessageBox::information(this, "Success", "Login successful, returning to main menu.");
}
void MainWindow::onAppointmentsButtonClicked()
{
    qDebug() << "Appointments button clicked";
    AppointmentsDialog dialog(appointmentService, customerService,  this);
    dialog.exec();
}

void MainWindow::onServicesButtonClicked()
{
    qDebug() << "Services button clicked";
    ServicesView view(servicesService, notesService, this);
    view.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Customers *dialog = new Customers(this);
    dialog->exec();
}
void MainWindow::onCreateAccountClicked()
{
    showTablePopup(); // Show the TablePopup when the button is clicked
}
void MainWindow::onContactUsButtonClicked()
{
    QMessageBox::information(this, "Contact Us", "Lucas\nlucas.pritchett@live.bemidjistate.edu\n""\nmichael\nmichael.wright@live.bemidjistate.edu");
}
