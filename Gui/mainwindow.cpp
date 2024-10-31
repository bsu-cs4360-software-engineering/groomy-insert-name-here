#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "tablepopup.h"
#include "customers.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/lprit/OneDrive/Documents/Gui/images/user.png");
    ui->user->setPixmap(pix);
    QPixmap pix2("C:/Users/lprit/OneDrive/Documents/Gui/images/security.png");
    ui->security->setPixmap(pix2);
    QPixmap pix3("C:/Users/lprit/OneDrive/Documents/Gui/images/courage.png");
    ui->courage->setPixmap(pix3);

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
void MainWindow::on_Login_clicked()
{
    QMessageBox::information(this, "login", "Login Success, Very nice!");
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
}
void MainWindow::on_commandLinkButton_clicked()
{
    // Show the TablePopup dialog
    TablePopup *dialog = new TablePopup(this);
    connect(dialog, &TablePopup::saveCompleted, this, &MainWindow::onSaveCompleted);
    dialog->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Customers *dialog = new Customers(this);
    dialog->exec();
}

