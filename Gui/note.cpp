
#include "note.h"

    Note::Note(int id, const QString &title, const QString &data, const QDateTime &createdDate)
    : id(id), title(title), data(data), createdDate(createdDate) {}

Note::Note() : id(1), title(""), data(""), createdDate(QDateTime::currentDateTime()) {}

QJsonObject Note::toJson() const {
    QJsonObject json;
    json["id"] = id;
    json["title"] = title;
    json["data"] = data;
    json["created_date"] = createdDate.toString(Qt::ISODate);
    return json;
}

Note Note::fromJson(const QJsonObject &json) {
    return Note(
        json["id"].toInt(),
        json["title"].toString(),
        json["data"].toString(),
        QDateTime::fromString(json["created_date"].toString(), Qt::ISODate)
        );
}
