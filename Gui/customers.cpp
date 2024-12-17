#include "customers.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>

Customers::Customers(QWidget *parent)
    : QDialog(parent), customerService(new CustomerService("customers.json")), signalMapper(new QSignalMapper(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    commandLinkButton = new QCommandLinkButton("Add Customer", this);
    connect(commandLinkButton, &QCommandLinkButton::clicked, this, &Customers::onCommandLinkButtonClicked);
    layout->addWidget(commandLinkButton);

    QLabel *label = new QLabel("Customers", this);
    layout->addWidget(label);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(7); // Add an extra column for actions
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Stretch columns to fit the available space
    tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "First Name" << "Last Name" << "Email" << "Phone Number" << "Address" << "Actions");
    layout->addWidget(tableWidget);

    setupTable();

    setLayout(layout);
    setWindowTitle("Customers");
    resize(1000, 800);
}

void Customers::setupTable()
{
    loadJsonData();
    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Resize ID column to contents
    for (int i = 1; i < tableWidget->columnCount(); ++i) {
        tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch); // Stretch other columns
    }

}

void Customers::loadJsonData()
{
    QFile file("customers.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray()) {
        qWarning() << "Invalid JSON format in file";
        return;
    }

    QJsonArray jsonArray = document.array();
    tableWidget->setRowCount(jsonArray.size());

    for (int row = 0; row < jsonArray.size(); ++row) {
        QJsonObject jsonObject = jsonArray.at(row).toObject();
        Customer customer = Customer::fromJson(jsonObject);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(customer.id)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(customer.firstName));
        tableWidget->setItem(row, 2, new QTableWidgetItem(customer.lastName));
        tableWidget->setItem(row, 3, new QTableWidgetItem(customer.email));
        tableWidget->setItem(row, 4, new QTableWidgetItem(customer.phoneNumber));
        tableWidget->setItem(row, 5, new QTableWidgetItem(customer.address));
        addActionButtons(row);
    }
}

void Customers::addCustomerToJson(const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &address)
{
    QFile file("customers.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = document.array();

    int newId = jsonArray.size() + 1;
    Customer newCustomer(newId, firstName, lastName, email, phoneNumber, address);
    jsonArray.append(newCustomer.toJson());

    document.setArray(jsonArray);
    file.resize(0);
    file.write(document.toJson());
    file.close();

    loadJsonData();
}

void Customers::addActionButtons(int row)
{
    QWidget *actionWidget = new QWidget(this);
    QHBoxLayout *actionLayout = new QHBoxLayout(actionWidget);
    actionLayout->setContentsMargins(0, 0, 0, 0);

    QPushButton *viewButton = new QPushButton("View", actionWidget);
    QPushButton *editButton = new QPushButton("Edit", actionWidget);
    QPushButton *deleteButton = new QPushButton("Delete", actionWidget);

    connect(viewButton, &QPushButton::clicked, [this, row]() { onViewButtonClicked(row); });
    connect(editButton, &QPushButton::clicked, [this, row]() { onEditButtonClicked(row); });
    connect(deleteButton, &QPushButton::clicked, [this, row]() { onDeleteButtonClicked(row); });

    actionLayout->addWidget(viewButton);
    actionLayout->addWidget(editButton);
    actionLayout->addWidget(deleteButton);
    actionWidget->setLayout(actionLayout);

    tableWidget->setCellWidget(row, 6, actionWidget);
}

void Customers::onViewButtonClicked(int row)
{
    QString customerDetails = QString("ID: %1\nFirst Name: %2\nLast Name: %3\nEmail: %4\nPhone Number: %5\nAddress: %6")
    .arg(tableWidget->item(row, 0)->text())
        .arg(tableWidget->item(row, 1)->text())
        .arg(tableWidget->item(row, 2)->text())
        .arg(tableWidget->item(row, 3)->text())
        .arg(tableWidget->item(row, 4)->text())
        .arg(tableWidget->item(row, 5)->text());
    QMessageBox::information(this, "Customer Details", customerDetails);
}

void Customers::onEditButtonClicked(int row)
{
    bool ok;
    QString firstName = QInputDialog::getText(this, "Edit First Name", "First Name:", QLineEdit::Normal, tableWidget->item(row, 1)->text(), &ok);
    if (ok && !firstName.isEmpty()) {
        tableWidget->item(row, 1)->setText(firstName);
    }
    QString lastName = QInputDialog::getText(this, "Edit Last Name", "Last Name:", QLineEdit::Normal, tableWidget->item(row, 2)->text(), &ok);
    if (ok && !lastName.isEmpty()) {
        tableWidget->item(row, 2)->setText(lastName);
    }
    QString email = QInputDialog::getText(this, "Edit Email", "Email:", QLineEdit::Normal, tableWidget->item(row, 3)->text(), &ok);
    if (ok && !email.isEmpty()) {
        tableWidget->item(row, 3)->setText(email);
    }
    QString phoneNumber = QInputDialog::getText(this, "Edit Phone Number", "Phone Number:", QLineEdit::Normal, tableWidget->item(row, 4)->text(), &ok);
    if (ok && !phoneNumber.isEmpty()) {
        tableWidget->item(row, 4)->setText(phoneNumber);
    }
    QString address = QInputDialog::getText(this, "Edit Address", "Address:", QLineEdit::Normal, tableWidget->item(row, 5)->text(), &ok);
    if (ok && !address.isEmpty()) {
        tableWidget->item(row, 5)->setText(address);
    }

    // Update JSON file
    QFile file("customers.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = document.array();

    QJsonObject jsonObject = jsonArray.at(row).toObject();
    jsonObject["firstName"] = firstName;
    jsonObject["lastName"] = lastName;
    jsonObject["email"] = email;
    jsonObject["phoneNumber"] = phoneNumber;
    jsonObject["address"] = address;

    jsonArray.replace(row, jsonObject);
    document.setArray(jsonArray);
    file.resize(0);
    file.write(document.toJson());
    file.close();
}

void Customers::onDeleteButtonClicked(int row)
{
    tableWidget->removeRow(row);

    // Update JSON file
    QFile file("customers.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = document.array();

    jsonArray.removeAt(row);
    document.setArray(jsonArray);
    file.resize(0);
    file.write(document.toJson());
    file.close();
}

void Customers::onCommandLinkButtonClicked()
{
    bool ok;
    QString firstName = QInputDialog::getText(this, "Add Customer", "First Name:", QLineEdit::Normal, "", &ok);
    if (ok && !firstName.isEmpty()) {
        QString lastName = QInputDialog::getText(this, "Add Customer", "Last Name:", QLineEdit::Normal, "", &ok);
        if (ok && !lastName.isEmpty()) {
            QString email = QInputDialog::getText(this, "Add Customer", "Email:", QLineEdit::Normal, "", &ok);
            if (ok && !email.isEmpty()) {
                QString phoneNumber = QInputDialog::getText(this, "Add Customer", "Phone Number:", QLineEdit::Normal, "", &ok);
                if (ok && !phoneNumber.isEmpty()) {
                    QString address = QInputDialog::getText(this, "Add Customer", "Address:", QLineEdit::Normal, "", &ok);
                    if (ok && !address.isEmpty()) {
                        addCustomerToJson(firstName, lastName, email, phoneNumber, address);
                    }
                }
            }
        }
    }
}
