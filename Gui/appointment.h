#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QJsonObject>
#include <QDateTime>
#include <QString>

class Appointment {
public:
    int id;
    QString title;
    QString description;
    QString location;
    QDateTime startTime;
    QDateTime endTime;

    Appointment(int id, const QString &title, const QString &description, const QString &location, const QDateTime &startTime, const QDateTime &endTime);
    Appointment(); // Default constructor
    QJsonObject toJson() const;
    static Appointment fromJson(const QJsonObject &json);
};

#endif // APPOINTMENT_H
