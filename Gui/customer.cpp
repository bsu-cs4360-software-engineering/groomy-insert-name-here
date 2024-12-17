#include "customer.h"

Customer::Customer(int id, const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &address)
    : id(id), firstName(firstName), lastName(lastName), email(email), phoneNumber(phoneNumber), address(address) {}

Customer::Customer() : id(0), firstName(""), lastName(""), email(""), phoneNumber(""), address("") {} // Implement default constructor

QJsonObject Customer::toJson() const {
    QJsonObject json;
    json["id"] = id;
    json["firstName"] = firstName;
    json["lastName"] = lastName;
    json["email"] = email;
    json["phoneNumber"] = phoneNumber;
    json["address"] = address;
    return json;
}

Customer Customer::fromJson(const QJsonObject &json) {
    return Customer(
        json["id"].toInt(),
        json["firstName"].toString(),
        json["lastName"].toString(),
        json["email"].toString(),
        json["phoneNumber"].toString(),
        json["address"].toString()
        );
}
