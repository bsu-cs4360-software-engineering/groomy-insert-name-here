#include "customer.h"

Customer::Customer(const QJsonObject &json)
{
    firstName = json["firstName"].toString();
    lastName = json["lastName"].toString();
    email = json["email"].toString();
    phoneNumber = json["phoneNumber"].toString();
    address = json["address"].toString();
}

QString Customer::getFirstName() const { return firstName; }
QString Customer::getLastName() const { return lastName; }
QString Customer::getEmail() const { return email; }
QString Customer::getPhoneNumber() const { return phoneNumber; }
QString Customer::getAddress() const { return address; }

void Customer::setFirstName(const QString &firstName) { this->firstName = firstName; }
void Customer::setLastName(const QString &lastName) { this->lastName = lastName; }
void Customer::setEmail(const QString &email) { this->email = email; }
void Customer::setPhoneNumber(const QString &phoneNumber) { this->phoneNumber = phoneNumber; }
void Customer::setAddress(const QString &address) { this->address = address; }

QJsonObject Customer::toJson() const
{
    QJsonObject json;
    json["firstName"] = firstName;
    json["lastName"] = lastName;
    json["email"] = email;
    json["phoneNumber"] = phoneNumber;
    json["address"] = address;
    return json;
}
