#ifndef EDITNOTEVIEW_H
#define EDITNOTEVIEW_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include "note.h"

class EditNoteView : public QDialog
{
    Q_OBJECT

public:
    explicit EditNoteView(Note &note, QWidget *parent = nullptr);

private slots:
    void onSaveButtonClicked();

private:
    Note &note;
    QLineEdit *titleEdit;
    QTextEdit *dataEdit;
};

#endif // EDITNOTEVIEW_H
