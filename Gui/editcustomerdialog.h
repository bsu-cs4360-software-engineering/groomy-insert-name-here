#ifndef EDITCUSTOMERDIALOG_H
#define EDITCUSTOMERDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

class EditCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCustomerDialog(const QJsonObject &customer, QWidget *parent = nullptr);
    QJsonObject getUpdatedCustomer() const;

private:
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *emailEdit;
    QLineEdit *phoneNumberEdit;
    QLineEdit *addressEdit;
};

#endif // EDITCUSTOMERDIALOG_H
