#include "service.h"

Service::Service(int id, const QString &name, const QString &description, double price)
    : id(id), name(name), description(description), price(price) {}

Service::Service() : id(0), name(""), description(""), price(0.0) {} // Implement default constructor

QJsonObject Service::toJson() const {
    QJsonObject json;
    json["id"] = id;
    json["name"] = name;
    json["description"] = description;
    json["price"] = price;
    return json;
}

Service Service::fromJson(const QJsonObject &json) {
    return Service(
        json["id"].toInt(),
        json["name"].toString(),
        json["description"].toString(),
        json["price"].toDouble()
        );
}
