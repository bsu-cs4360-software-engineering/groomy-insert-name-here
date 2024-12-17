#ifndef NOTESERVICE_H
#define NOTESERVICE_H

#include "note.h"
#include <QList>
#include <QJsonArray>
#include <vector>

class NotesService {
public:
    NotesService();
    NotesService(const std::string &notesFile, const std::string &customerNotesFile, const std::string &appointmentNotesFile, const std::string &serviceNotesFile);

    void addNote(const Note &note);
    void updateNote(const Note &note);
    void deleteNote(int id);
    std::vector<Note> getAllNotes() const;
    std::vector<Note> getNotesByCustomerId(int customerId) const;
    std::vector<Note> getNotesByAppointmentId(int appointmentId) const;
    std::vector<Note> getNotesByServiceId(int serviceId) const; // Add this method declaration
    void createNoteForCustomer(const Note &note, int customerId);
    void createNoteForService(const Note &note, int serviceId);

private:
    std::vector<Note> notes;
    std::string notesFile;
    std::string customerNotesFile;
    std::string appointmentNotesFile;
    std::string serviceNotesFile;

    void loadNotes();
    void saveNotes() const;
};

#endif // NOTESERVICE_H
