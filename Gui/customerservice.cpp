#include "customerservice.h"
#include <QJsonDocument>
#include <QMessageBox>

CustomerService::CustomerService(const QString &filePath) : filePath(filePath) {}

QList<Customer> CustomerService::getAllCustomers() const
{
    QJsonArray jsonArray = loadJsonArray();
    QList<Customer> customers;
    for (const QJsonValue &value : jsonArray)
    {
        customers.append(Customer(value.toObject()));
    }
    return customers;
}

void CustomerService::addCustomer(const Customer &customer)
{
    QJsonArray jsonArray = loadJsonArray();
    jsonArray.append(customer.toJson());
    saveJsonArray(jsonArray);
}

void CustomerService::updateCustomer(const Customer &customer)
{
    QJsonArray jsonArray = loadJsonArray();
    for (int i = 0; i < jsonArray.size(); ++i)
    {
        if (jsonArray[i].toObject()["email"].toString() == customer.getEmail())
        {
            jsonArray[i] = customer.toJson();
            break;
        }
    }
    saveJsonArray(jsonArray);
}

void CustomerService::deleteCustomer(const QString &email)
{
    QJsonArray jsonArray = loadJsonArray();
    for (int i = 0; i < jsonArray.size(); ++i)
    {
        if (jsonArray[i].toObject()["email"].toString() == email)
        {
            jsonArray.removeAt(i);
            break;
        }
    }
    saveJsonArray(jsonArray);
}

QJsonArray CustomerService::loadJsonArray() const
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "Could not open customers.json");
        return QJsonArray();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray())
    {
        QMessageBox::critical(nullptr, "Error", "Invalid JSON format in customers.json");
        return QJsonArray();
    }

    return document.array();
}

void CustomerService::saveJsonArray(const QJsonArray &jsonArray) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "Could not open customers.json for writing");
        return;
    }

    QJsonDocument document;
    document.setArray(jsonArray);
    file.write(document.toJson());
    file.close();
}
