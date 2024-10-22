#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

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
     connect(ui->Login, &QPushButton::clicked, this, &MainWindow::on_Login_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Login_clicked() {
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QMessageBox::information(this, "Login Info", "Username: " + username + "\nPassword: " + password);
}
