#ifndef NOTESDIALOG_H
#define NOTESDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <memory>
#include "noteservice.h"

class NotesDialog : public QDialog {
    Q_OBJECT

public:
    explicit NotesDialog(int serviceId, std::shared_ptr<NotesService> notesService, QWidget *parent = nullptr);

private slots:
    void onAddNoteButtonClicked();
    void onEditNoteButtonClicked(int noteId);
    void onDeleteNoteButtonClicked(int noteId);
    void onViewNoteButtonClicked(int noteId);

private:
    int serviceId;
    std::shared_ptr<NotesService> notesService;
    QTableWidget *tableNotes;

    void loadNotes(); // Declaration only
};

#endif // NOTESDIALOG_H
