
#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QDateTime>
#include <QJsonObject>

class Note {
public:
    Note(int id, const QString &title, const QString &data, const QDateTime &createdDate);
    Note();

    QJsonObject toJson() const;
    static Note fromJson(const QJsonObject &json);

    int id;
    QString title;
    QString data;
    QDateTime createdDate;
};

#endif // NOTE_H
