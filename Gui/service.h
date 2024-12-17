#ifndef SERVICE_H
#define SERVICE_H

#include <QJsonObject>
#include <QString>

class Service {
public:
    int id;
    QString name;
    QString description;
    double price;

    Service(int id, const QString &name, const QString &description, double price);
    Service(); // Default constructor
    QJsonObject toJson() const;
    static Service fromJson(const QJsonObject &json);
};

#endif // SERVICE_H
