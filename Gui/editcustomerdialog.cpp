#include "editcustomerdialog.h"
#include <QLabel>

EditCustomerDialog::EditCustomerDialog(const QJsonObject &customer, QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    firstNameEdit = new QLineEdit(customer["firstName"].toString(), this);
    lastNameEdit = new QLineEdit(customer["lastName"].toString(), this);
    emailEdit = new QLineEdit(customer["email"].toString(), this);
    phoneNumberEdit = new QLineEdit(customer["phoneNumber"].toString(), this);
    addressEdit = new QLineEdit(customer["address"].toString(), this);

    layout->addWidget(new QLabel("First Name:", this));
    layout->addWidget(firstNameEdit);
    layout->addWidget(new QLabel("Last Name:", this));
    layout->addWidget(lastNameEdit);
    layout->addWidget(new QLabel("Email:", this));
    layout->addWidget(emailEdit);
    layout->addWidget(new QLabel("Phone Number:", this));
    layout->addWidget(phoneNumberEdit);
    layout->addWidget(new QLabel("Address:", this));
    layout->addWidget(addressEdit);

    QPushButton *saveButton = new QPushButton("Save", this);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, &QDialog::accept);

    setLayout(layout);
    setWindowTitle("Edit Customer");
    resize(300, 200);
}

QJsonObject EditCustomerDialog::getUpdatedCustomer() const
{
    QJsonObject customer;
    customer["firstName"] = firstNameEdit->text();
    customer["lastName"] = lastNameEdit->text();
    customer["email"] = emailEdit->text();
    customer["phoneNumber"] = phoneNumberEdit->text();
    customer["address"] = addressEdit->text();
    return customer;
}
