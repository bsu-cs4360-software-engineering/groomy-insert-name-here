#include "customerservice.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

CustomerService::CustomerService(const QString &filePath)
    : filePath(filePath) {}

std::vector<Customer> CustomerService::getAllCustomers() {
    return loadCustomers();
}

Customer CustomerService::getCustomerById(int id) {
    auto customers = loadCustomers();
    for (const auto &customer : customers) {
        if (customer.id == id) {
            return customer;
        }
    }
    return Customer();
}

void CustomerService::createCustomer(const Customer &customer) {
    auto customers = loadCustomers();
    customers.push_back(customer);
    saveCustomers(customers);
}

void CustomerService::updateCustomer(const Customer &customer) {
    auto customers = loadCustomers();
    for (auto &c : customers) {
        if (c.id == customer.id) {
            c = customer;
            break;
        }
    }
    saveCustomers(customers);
}

void CustomerService::deleteCustomer(int id) {
    auto customers = loadCustomers();
    customers.erase(std::remove_if(customers.begin(), customers.end(), [id](const Customer &customer) {
                        return customer.id == id;
                    }), customers.end());
    saveCustomers(customers);
}

std::vector<Customer> CustomerService::loadCustomers() {
    std::vector<Customer> customers;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << filePath;
        return customers;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return customers;
    }

    QJsonArray jsonArray = document.array();
    for (const auto &jsonValue : jsonArray) {
        customers.push_back(Customer::fromJson(jsonValue.toObject()));
    }

    return customers;
}

void CustomerService::saveCustomers(const std::vector<Customer> &customers) {
    QJsonArray jsonArray;
    for (const auto &customer : customers) {
        jsonArray.append(customer.toJson());
    }

    QJsonDocument document(jsonArray);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << filePath;
        return;
    }

    file.write(document.toJson());
    file.close();
}


