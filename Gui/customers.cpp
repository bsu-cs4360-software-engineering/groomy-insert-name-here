#include "customers.h"
#include "customerservice.h"
#include "viewcustomerdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QColor>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
#include <QSignalMapper>

Customers::Customers(QWidget *parent) :
    QDialog(parent),
    tableWidget(new QTableWidget(this)),
    commandLinkButton(new QCommandLinkButton("New Customer", this)),
    customerService(nullptr),
    signalMapper(new QSignalMapper(this))
{
    // Setup UI for Customers dialog
    setWindowTitle("Customers");
    resize(600, 600); // Set the size of the dialog

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(commandLinkButton);
    layout->addWidget(tableWidget);
    setLayout(layout);

    setupTable();

    // Ensure the resources directory exists
    QString writableLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(writableLocation);
    if (!dir.exists("resources")) {
        if (!dir.mkpath("resources")) {
            QMessageBox::critical(this, "Error", "Could not create resources directory");
            return;
        }
    }

    // Initialize CustomerService with the correct path
    QString filePath = writableLocation + "/resources/customers.json";
    qDebug() << "JSON file path:" << filePath;
    customerService = new CustomerService(filePath);

    loadJsonData();

    connect(commandLinkButton, &QCommandLinkButton::clicked, this, &Customers::onCommandLinkButtonClicked);
    connect(signalMapper, SIGNAL(mappedInt(int)), this, SLOT(onDeleteButtonClicked(int))); // Connect QSignalMapper

}

Customers::~Customers()
{
    delete customerService;
}

void Customers::setupTable()
{
    tableWidget->setRowCount(0); // Initially set to 0 rows
    tableWidget->setColumnCount(4); // Set the number of columns (Name, Email, Phone Number, Actions)
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Email" << "Phone Number" << "Actions");
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Customers::loadJsonData()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/resources/customers.json";
    qDebug() << "Loading JSON file from path:" << filePath;
    QFile file(filePath); // Ensure the path is correct
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file:" << file.errorString();
        QMessageBox::critical(this, "Error", "Could not open customers.json");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray())
    {
        qDebug() << "Invalid JSON format in customers.json";
        QMessageBox::critical(this, "Error", "Invalid JSON format in customers.json");
        return;
    }

    QJsonArray jsonArray = document.array();
    qDebug() << "Loaded JSON array:" << jsonArray;
    tableWidget->setRowCount(jsonArray.size());
    deletedRows.resize(jsonArray.size(), false);

    for (int row = 0; row < jsonArray.size(); ++row)
    {
        QJsonObject jsonObject = jsonArray[row].toObject();
        qDebug() << "Loaded JSON object:" << jsonObject;
        tableWidget->setItem(row, 0, new QTableWidgetItem(jsonObject["firstName"].toString() + " " + jsonObject["lastName"].toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(jsonObject["email"].toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(jsonObject["phoneNumber"].toString()));

        QWidget *actionWidget = new QWidget();
        QHBoxLayout *actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);

        QPushButton *viewButton = new QPushButton("View");
        QPushButton *editButton = new QPushButton("Edit");
        QPushButton *deleteButton = new QPushButton("Delete");

        viewButton->setObjectName("ViewButton");
        editButton->setObjectName("EditButton");
        deleteButton->setObjectName("DeleteButton");

        connect(viewButton, &QPushButton::clicked, this, &Customers::onViewButtonClicked);
        connect(editButton, &QPushButton::clicked, this, &Customers::onEditButtonClicked);
        connect(deleteButton, SIGNAL(clicked()), signalMapper, SLOT(map())); // Connect delete button to QSignalMapper
        signalMapper->setMapping(deleteButton, row); // Map delete button to row index

        actionLayout->addWidget(viewButton);
        actionLayout->addWidget(editButton);
        actionLayout->addWidget(deleteButton);
        actionWidget->setLayout(actionLayout);

        tableWidget->setCellWidget(row, 3, actionWidget);
    }
}

void Customers::onViewButtonClicked()
{
    qDebug() << "View button clicked";
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        int row = -1;
        for (int i = 0; i < tableWidget->rowCount(); ++i)
        {
            if (tableWidget->cellWidget(i, 3)->findChild<QPushButton *>("ViewButton") == button)
            {
                row = i;
                break;
            }
        }

        if (row != -1)
        {
            QString email = tableWidget->item(row, 1)->text();
            QJsonArray jsonArray = customerService->loadJsonArray();
            for (const QJsonValue &value : jsonArray)
            {
                QJsonObject jsonObject = value.toObject();
                if (jsonObject["email"].toString() == email)
                {
                    QString details = QString("First Name: %1\nLast Name: %2\nEmail: %3\nPhone Number: %4\nAddress: %5")
                    .arg(jsonObject["firstName"].toString())
                        .arg(jsonObject["lastName"].toString())
                        .arg(jsonObject["email"].toString())
                        .arg(jsonObject["phoneNumber"].toString())
                        .arg(jsonObject["address"].toString());

                    QMessageBox::information(this, "Customer Details", details);
                    break;
                }
            }
        }
    }
}

void Customers::onEditButtonClicked()
{
    qDebug() << "Edit button clicked";
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        int row = -1;
        for (int i = 0; i < tableWidget->rowCount(); ++i)
        {
            if (tableWidget->cellWidget(i, 3)->findChild<QPushButton *>("EditButton") == button)
            {
                row = i;
                break;
            }
        }

        if (row != -1)
        {
            QString email = tableWidget->item(row, 1)->text();
            QJsonArray jsonArray = customerService->loadJsonArray();
            for (const QJsonValue &value : jsonArray)
            {
                QJsonObject jsonObject = value.toObject();
                if (jsonObject["email"].toString() == email)
                {
                    EditCustomerDialog editDialog(jsonObject, this);
                    if (editDialog.exec() == QDialog::Accepted)
                    {
                        QJsonObject updatedCustomer = editDialog.getUpdatedCustomer();
                        Customer customer(updatedCustomer);
                        customerService->updateCustomer(customer);
                        loadJsonData(); // Reload the data to update the table
                    }
                    break;
                }
            }
        }
    }
}

void Customers::onDeleteButtonClicked(int row)
{
    qDebug() << "Delete button clicked for row" << row;

    if (row != -1)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete Customer", "Are you sure you want to delete this customer?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QString email = tableWidget->item(row, 1)->text();
            customerService->deleteCustomer(email);
            tableWidget->removeRow(row); // Remove row from table
            qDebug() << "Customer deleted from table";
        }
    }
    else
    {
        qDebug() << "Row not found";
    }
}

void Customers::onCommandLinkButtonClicked()
{
    bool ok;

    QString firstName = QInputDialog::getText(this, tr("Add Customer"), tr("First Name:"), QLineEdit::Normal, "", &ok);
    if (!ok || firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, tr("Add Customer"), tr("Last Name:"), QLineEdit::Normal, "", &ok);
    if (!ok || lastName.isEmpty()) return;

    QString email = QInputDialog::getText(this, tr("Add Customer"), tr("Email:"), QLineEdit::Normal, "", &ok);
    if (!ok || email.isEmpty()) return;

    QString phoneNumber = QInputDialog::getText(this, tr("Add Customer"), tr("Phone Number:"), QLineEdit::Normal, "", &ok);
    if (!ok || phoneNumber.isEmpty()) return;

    QString address = QInputDialog::getText(this, tr("Add Customer"), tr("Address:"), QLineEdit::Normal, "", &ok);
    if (!ok || address.isEmpty()) return;

    addCustomerToJson(firstName, lastName, email, phoneNumber, address);
    loadJsonData(); // Reload the data to update the table
}

void Customers::addCustomerToJson(const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &address)
{
    Customer customer(QJsonObject{
        {"firstName", firstName},
        {"lastName", lastName},
        {"email", email},
        {"phoneNumber", phoneNumber},
        {"address", address}
    });

    customerService->addCustomer(customer);
}
