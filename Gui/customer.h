#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QJsonObject>
#include <QString>

class Customer {
public:
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString phoneNumber;
    QString address;

    Customer(int id, const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &address);
    Customer(); // Default constructor
    QJsonObject toJson() const;
    static Customer fromJson(const QJsonObject &json);
};

#endif // CUSTOMER_H
