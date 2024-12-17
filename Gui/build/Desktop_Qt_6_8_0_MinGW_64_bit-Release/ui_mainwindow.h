/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonLogin;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLabel *Title;
    QWidget *menu_area;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *appointments;
    QPushButton *services;
    QPushButton *pushButton_4;
    QLabel *security;
    QLabel *user;
    QCommandLinkButton *pushButtonCreateAccount;
    QLabel *courage;
    QWidget *widget;
    QDateEdit *dateEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        QFont font;
        font.setItalic(true);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(125, 125, 125);"));
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        MainWindow->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonLogin = new QPushButton(centralwidget);
        pushButtonLogin->setObjectName("pushButtonLogin");
        pushButtonLogin->setGeometry(QRect(700, 320, 131, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(12);
        pushButtonLogin->setFont(font1);
        pushButtonLogin->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        labelUsername = new QLabel(centralwidget);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setGeometry(QRect(710, 230, 71, 20));
        labelUsername->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(710, 229, 111, 51));
        lineEditUsername = new QLineEdit(centralwidget);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(710, 180, 111, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        lineEditUsername->setFont(font2);
        lineEditUsername->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEditUsername->setFrame(true);
        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(710, 230, 111, 41));
        lineEditPassword->setFont(font2);
        lineEditPassword->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        lineEditPassword->setAutoFillBackground(false);
        lineEditPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(250, 0, 201, 121));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(36);
        font3.setBold(false);
        font3.setItalic(true);
        Title->setFont(font3);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
""));
        menu_area = new QWidget(centralwidget);
        menu_area->setObjectName("menu_area");
        menu_area->setGeometry(QRect(0, 0, 200, 1080));
        menu_area->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));
        pushButton = new QPushButton(menu_area);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-10, 20, 211, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        font4.setPointSize(16);
        font4.setBold(true);
        pushButton->setFont(font4);
        pushButton->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(245, 245, 245);"));
        pushButton_2 = new QPushButton(menu_area);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(-10, 80, 211, 31));
        pushButton_2->setFont(font4);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(menu_area);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(-10, 660, 211, 31));
        pushButton_3->setFont(font4);
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        appointments = new QPushButton(menu_area);
        appointments->setObjectName("appointments");
        appointments->setGeometry(QRect(-10, 110, 211, 31));
        appointments->setFont(font4);
        appointments->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        services = new QPushButton(menu_area);
        services->setObjectName("services");
        services->setGeometry(QRect(-10, 50, 211, 31));
        services->setFont(font4);
        services->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 255);"));
        pushButton_4 = new QPushButton(menu_area);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 140, 201, 31));
        pushButton_4->setFont(font4);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 255);"));
        security = new QLabel(centralwidget);
        security->setObjectName("security");
        security->setGeometry(QRect(670, 240, 30, 30));
        security->setStyleSheet(QString::fromUtf8("image: url(:/resources/images/security.png);"));
        security->setPixmap(QPixmap(QString::fromUtf8("images/security.png")));
        security->setScaledContents(true);
        user = new QLabel(centralwidget);
        user->setObjectName("user");
        user->setGeometry(QRect(670, 180, 30, 30));
        user->setStyleSheet(QString::fromUtf8("image: url(:/resources/images/user.png);"));
        user->setPixmap(QPixmap(QString::fromUtf8("images/user.png")));
        user->setScaledContents(true);
        pushButtonCreateAccount = new QCommandLinkButton(centralwidget);
        pushButtonCreateAccount->setObjectName("pushButtonCreateAccount");
        pushButtonCreateAccount->setGeometry(QRect(630, 270, 261, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Calibri")});
        font5.setPointSize(12);
        font5.setUnderline(true);
        pushButtonCreateAccount->setFont(font5);
        pushButtonCreateAccount->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        pushButtonCreateAccount->setIcon(icon);
        courage = new QLabel(centralwidget);
        courage->setObjectName("courage");
        courage->setGeometry(QRect(260, 160, 201, 251));
        courage->setStyleSheet(QString::fromUtf8("image: url(:/resources/images/courage.png);"));
        courage->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/courage.png")));
        courage->setScaledContents(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-10, 0, 1980, 20));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(1000, 20, 211, 41));
        dateEdit->setFont(font4);
        dateEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        dateEdit->setReadOnly(false);
        dateEdit->setCurrentSection(QDateTimeEdit::Section::MonthSection);
        dateEdit->setCalendarPopup(true);
        dateEdit->setTimeSpec(Qt::TimeSpec::LocalTime);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        labelUsername->setText(QString());
        labelPassword->setText(QString());
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "username", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "password", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Groomy", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Customers", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Contact Us", nullptr));
        appointments->setText(QCoreApplication::translate("MainWindow", "Appointments", nullptr));
        services->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Invoices", nullptr));
        security->setText(QString());
        user->setText(QString());
        pushButtonCreateAccount->setText(QCoreApplication::translate("MainWindow", "Create new account here!", nullptr));
        courage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
