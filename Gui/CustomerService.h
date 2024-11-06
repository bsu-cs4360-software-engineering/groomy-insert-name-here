#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "customer.h"

class CustomerService
{
public:
    CustomerService(const QString &filePath);

    QList<Customer> getAllCustomers() const;
    void addCustomer(const Customer &customer);
    void updateCustomer(const Customer &customer);
    void deleteCustomer(const QString &email);
    QJsonArray loadJsonArray() const;

private:
    QString filePath;
    void saveJsonArray(const QJsonArray &jsonArray) const;
};

#endif // CUSTOMERSERVICE_H
