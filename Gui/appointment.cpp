#include "appointment.h"

Appointment::Appointment(int id, const QString &title, const QString &description, const QString &location, const QDateTime &startTime, const QDateTime &endTime)
    : id(id), title(title), description(description), location(location), startTime(startTime), endTime(endTime) {}

Appointment::Appointment() : id(0), title(""), description(""), location(""), startTime(QDateTime::currentDateTime()), endTime(QDateTime::currentDateTime()) {} // Implement default constructor

QJsonObject Appointment::toJson() const {
    QJsonObject json;
    json["id"] = id;
    json["title"] = title;
    json["description"] = description;
    json["location"] = location;
    json["start_time"] = startTime.toString(Qt::ISODate);
    json["end_time"] = endTime.toString(Qt::ISODate);
    return json;
}

Appointment Appointment::fromJson(const QJsonObject &json) {
    return Appointment(
        json["id"].toInt(),
        json["title"].toString(),
        json["description"].toString(),
        json["location"].toString(),
        QDateTime::fromString(json["start_time"].toString(), Qt::ISODate),
        QDateTime::fromString(json["end_time"].toString(), Qt::ISODate)
        );
}
