#include "notesdialog.h"
#include "noteservice.h"
#include "editnoteview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

NotesDialog::NotesDialog(int serviceId, std::shared_ptr<NotesService> notesService, QWidget *parent)
    : QDialog(parent), serviceId(serviceId), notesService(notesService)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Add Note button at the top
    QPushButton *addNoteButton = new QPushButton("Add Note", this);
    connect(addNoteButton, &QPushButton::clicked, this, &NotesDialog::onAddNoteButtonClicked);
    layout->addWidget(addNoteButton);

    QLabel *label = new QLabel("Notes", this);
    layout->addWidget(label);

    tableNotes = new QTableWidget(this);
    tableNotes->setColumnCount(5); // Increase column count to accommodate action buttons
    tableNotes->setHorizontalHeaderLabels(QStringList() << "ID" << "Title" << "Data" << "Created Date" << "Actions");
    layout->addWidget(tableNotes);

    loadNotes();

    setLayout(layout);
    setWindowTitle("Notes");
    resize(800, 600);
}

void NotesDialog::loadNotes()
{
    qDebug() << "Loading notes for service ID:" << serviceId;
    std::vector<Note> notes = notesService->getNotesByServiceId(serviceId);
    tableNotes->setRowCount(notes.size());

    for (std::size_t row = 0; row < notes.size(); ++row) {
        const Note &note = notes[row];
        qDebug() << "Processing note:" << note.id;
        tableNotes->setItem(row, 0, new QTableWidgetItem(QString::number(note.id)));
        tableNotes->setItem(row, 1, new QTableWidgetItem(note.title));
        tableNotes->setItem(row, 2, new QTableWidgetItem(note.data));
        tableNotes->setItem(row, 3, new QTableWidgetItem(note.createdDate.toString("yyyy-MM-dd HH:mm")));

        // Create a widget to hold the action buttons
        QWidget *actionWidget = new QWidget(this);
        QHBoxLayout *actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);

        // Add view button
        QPushButton *viewButton = new QPushButton("View", this);
        connect(viewButton, &QPushButton::clicked, this, [this, note]() {
            onViewNoteButtonClicked(note.id);
        });
        actionLayout->addWidget(viewButton);

        // Add edit button
        QPushButton *editButton = new QPushButton("Edit", this);
        connect(editButton, &QPushButton::clicked, this, [this, note]() {
            onEditNoteButtonClicked(note.id);
        });
        actionLayout->addWidget(editButton);

        // Add delete button
        QPushButton *deleteButton = new QPushButton("Delete", this);
        connect(deleteButton, &QPushButton::clicked, this, [this, note]() {
            onDeleteNoteButtonClicked(note.id);
        });
        actionLayout->addWidget(deleteButton);

        actionWidget->setLayout(actionLayout);
        tableNotes->setCellWidget(row, 4, actionWidget);
    }
    qDebug() << "Finished loading notes.";
}

void NotesDialog::onAddNoteButtonClicked()
{
    Note newNote;
    EditNoteView dialog(newNote, this);
    if (dialog.exec() == QDialog::Accepted) {
        notesService->createNoteForService(newNote, serviceId);
        loadNotes();
    }
}

void NotesDialog::onEditNoteButtonClicked(int noteId)
{
    for (Note &note : notesService->getAllNotes()) {
        if (note.id == noteId) {
            EditNoteView dialog(note, this);
            if (dialog.exec() == QDialog::Accepted) {
                notesService->updateNote(note);
                loadNotes();
            }
            break;
        }
    }
}

void NotesDialog::onDeleteNoteButtonClicked(int noteId)
{
    notesService->deleteNote(noteId);
    loadNotes();
}

void NotesDialog::onViewNoteButtonClicked(int noteId)
{
    for (const Note &note : notesService->getAllNotes()) {
        if (note.id == noteId) {
            // Display the note details in a dialog or any other way you prefer
            QMessageBox::information(this, "View Note", "Title: " + note.title + "\nData: " + note.data);
            break;
        }
    }
}
