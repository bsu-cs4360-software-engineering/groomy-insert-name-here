#include "editnoteview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

EditNoteView::EditNoteView(Note &note, QWidget *parent)
    : QDialog(parent), note(note)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    titleEdit = new QLineEdit(this);
    dataEdit = new QTextEdit(this);

    titleEdit->setText(note.title);
    dataEdit->setText(note.data);

    layout->addWidget(new QLabel("Title:", this));
    layout->addWidget(titleEdit);
    layout->addWidget(new QLabel("Note:", this));
    layout->addWidget(dataEdit);

    QPushButton *saveButton = new QPushButton("Save", this);
    connect(saveButton, &QPushButton::clicked, this, &EditNoteView::onSaveButtonClicked);
    layout->addWidget(saveButton);

    setLayout(layout);
    setWindowTitle("Edit Note");
    resize(400, 300);
}

void EditNoteView::onSaveButtonClicked()
{
    note.title = titleEdit->text();
    note.data = dataEdit->toPlainText();
    note.createdDate = QDateTime::currentDateTime();

    accept();
}
