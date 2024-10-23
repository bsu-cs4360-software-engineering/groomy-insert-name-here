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
    QPushButton *Login;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLabel *Title;
    QWidget *menu_area;
    QPushButton *pushButton;
    QLabel *security;
    QLabel *user;
    QCommandLinkButton *commandLinkButton;
    QLabel *courage;
    QWidget *widget;

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
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(132, 132, 132);\n"
"background-color: rgb(106, 106, 106);"));
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Login = new QPushButton(centralwidget);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(700, 320, 131, 24));
        Login->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
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
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setItalic(true);
        lineEditUsername->setFont(font1);
        lineEditUsername->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEditUsername->setFrame(true);
        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(710, 230, 111, 41));
        lineEditPassword->setFont(font1);
        lineEditPassword->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        lineEditPassword->setAutoFillBackground(false);
        lineEditPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);
        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(250, 0, 201, 121));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(36);
        font2.setBold(false);
        font2.setItalic(true);
        Title->setFont(font2);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
""));
        menu_area = new QWidget(centralwidget);
        menu_area->setObjectName("menu_area");
        menu_area->setGeometry(QRect(0, 0, 200, 1080));
        menu_area->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));
        pushButton = new QPushButton(menu_area);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-10, 170, 211, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Calibri")});
        font3.setPointSize(16);
        font3.setBold(true);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: rgb(245, 245, 245);"));
        security = new QLabel(centralwidget);
        security->setObjectName("security");
        security->setGeometry(QRect(670, 240, 30, 30));
        security->setPixmap(QPixmap(QString::fromUtf8("images/security.png")));
        security->setScaledContents(true);
        user = new QLabel(centralwidget);
        user->setObjectName("user");
        user->setGeometry(QRect(670, 180, 30, 30));
        user->setPixmap(QPixmap(QString::fromUtf8("images/user.png")));
        user->setScaledContents(true);
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(690, 280, 151, 31));
        QFont font4;
        font4.setPointSize(7);
        font4.setUnderline(true);
        commandLinkButton->setFont(font4);
        commandLinkButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        commandLinkButton->setIcon(icon);
        courage = new QLabel(centralwidget);
        courage->setObjectName("courage");
        courage->setGeometry(QRect(260, 160, 201, 251));
        courage->setPixmap(QPixmap(QString::fromUtf8("images/courage.png")));
        courage->setScaledContents(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-10, 0, 1980, 20));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        labelUsername->setText(QString());
        labelPassword->setText(QString());
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "username", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "password", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Groomy", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        security->setText(QString());
        user->setText(QString());
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "Create new account here!", nullptr));
        courage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
