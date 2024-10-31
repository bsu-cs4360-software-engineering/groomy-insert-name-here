#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QJsonObject>

class Customer
{
public:
    Customer(const QJsonObject &json);

    QString getFirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    QString getPhoneNumber() const;
    QString getAddress() const;

    void setFirstName(const QString &firstName);
    void setLastName(const QString &lastName);
    void setEmail(const QString &email);
    void setPhoneNumber(const QString &phoneNumber);
    void setAddress(const QString &address);

    QJsonObject toJson() const;

private:
    QString firstName;
    QString lastName;
    QString email;
    QString phoneNumber;
    QString address;
};


#endif // CUSTOMER_H
