#include "viewcustomerdialog.h"

ViewCustomerDialog::ViewCustomerDialog(const QJsonObject &customer, QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    firstNameLabel = new QLabel("First Name: " + customer["firstName"].toString(), this);
    lastNameLabel = new QLabel("Last Name: " + customer["lastName"].toString(), this);
    emailLabel = new QLabel("Email: " + customer["email"].toString(), this);
    phoneNumberLabel = new QLabel("Phone Number: " + customer["phoneNumber"].toString(), this);
    addressLabel = new QLabel("Address: " + customer["address"].toString(), this);

    layout->addWidget(firstNameLabel);
    layout->addWidget(lastNameLabel);
    layout->addWidget(emailLabel);
    layout->addWidget(phoneNumberLabel);
    layout->addWidget(addressLabel);

    QPushButton *closeButton = new QPushButton("Close", this);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    setLayout(layout);
    setWindowTitle("View Customer");
    resize(300, 200);
}
