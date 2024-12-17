#include "noteservice.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

NotesService::NotesService() {
    loadNotes();
}

NotesService::NotesService(const std::string &notesFile, const std::string &customerNotesFile, const std::string &appointmentNotesFile, const std::string &serviceNotesFile)
    : notesFile(notesFile), customerNotesFile(customerNotesFile), appointmentNotesFile(appointmentNotesFile), serviceNotesFile(serviceNotesFile) {
    loadNotes();
}

void NotesService::addNote(const Note &note) {
    notes.push_back(note);
    saveNotes();
}

void NotesService::updateNote(const Note &note) {
    for (auto &existingNote : notes) {
        if (existingNote.id == note.id) {
            existingNote = note;
            saveNotes();
            return;
        }
    }
}

void NotesService::deleteNote(int id) {
    notes.erase(std::remove_if(notes.begin(), notes.end(), [id](const Note &note) {
                    return note.id == id;
                }), notes.end());
    saveNotes();
}

std::vector<Note> NotesService::getAllNotes() const {
    return notes;
}

std::vector<Note> NotesService::getNotesByCustomerId(int customerId) const {
    std::vector<Note> customerNotes;
    QFile file(QString::fromStdString(customerNotesFile));
    if (!file.open(QIODevice::ReadOnly)) {
        return customerNotes;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        if (obj["fk_customer_id"].toInt() == customerId) {
            int noteId = obj["fk_note_id"].toInt();
            for (const Note &note : notes) {
                if (note.id == noteId) {
                    customerNotes.push_back(note);
                    break;
                }
            }
        }
    }
    return customerNotes;
}

std::vector<Note> NotesService::getNotesByAppointmentId(int appointmentId) const {
    std::vector<Note> appointmentNotes;
    QFile file(QString::fromStdString(appointmentNotesFile));
    if (!file.open(QIODevice::ReadOnly)) {
        return appointmentNotes;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        if (obj["fk_appointment_id"].toInt() == appointmentId) {
            int noteId = obj["fk_note_id"].toInt();
            for (const Note &note : notes) {
                if (note.id == noteId) {
                    appointmentNotes.push_back(note);
                    break;
                }
            }
        }
    }
    return appointmentNotes;
}

std::vector<Note> NotesService::getNotesByServiceId(int serviceId) const {
    std::vector<Note> serviceNotes;
    QFile file(QString::fromStdString(serviceNotesFile));
    if (!file.open(QIODevice::ReadOnly)) {
        return serviceNotes;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        if (obj["fk_service_id"].toInt() == serviceId) {
            int noteId = obj["fk_note_id"].toInt();
            for (const Note &note : notes) {
                if (note.id == noteId) {
                    serviceNotes.push_back(note);
                    break;
                }
            }
        }
    }
    return serviceNotes;
}

void NotesService::createNoteForCustomer(const Note &note, int customerId) {
    // Add the note to the notes vector
    notes.push_back(note);
    saveNotes();

    // Add the relationship to the customer_notes.json file
    QFile file(QString::fromStdString(customerNotesFile));
    if (!file.open(QIODevice::ReadWrite)) {
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();

    QJsonObject obj;
    obj["fk_customer_id"] = customerId;
    obj["fk_note_id"] = note.id;
    jsonArray.append(obj);

    doc.setArray(jsonArray);
    file.resize(0); // Clear the file
    file.write(doc.toJson());
    file.close();
}

void NotesService::createNoteForService(const Note &note, int serviceId) {
    // Add the note to the notes vector
    notes.push_back(note);
    saveNotes();

    // Add the relationship to the service_notes.json file
    QFile file(QString::fromStdString(serviceNotesFile));
    if (!file.open(QIODevice::ReadWrite)) {
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();

    QJsonObject obj;
    obj["fk_service_id"] = serviceId;
    obj["fk_note_id"] = note.id;
    jsonArray.append(obj);

    doc.setArray(jsonArray);
    file.resize(0); // Clear the file
    file.write(doc.toJson());
    file.close();
}

void NotesService::loadNotes() {
    QFile file(QString::fromStdString(notesFile));
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray) {
        notes.push_back(Note::fromJson(value.toObject()));
    }
}

void NotesService::saveNotes() const {
    QJsonArray jsonArray;
    for (const Note &note : notes) {
        jsonArray.append(note.toJson());
    }

    QJsonDocument doc(jsonArray);
    QFile file(QString::fromStdString(notesFile));
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    file.write(doc.toJson());
    file.close();
}
