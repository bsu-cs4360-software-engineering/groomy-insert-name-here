#include "editappointmentdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

EditAppointmentDialog::EditAppointmentDialog(Appointment &appointment, QWidget *parent)
    : QDialog(parent), appointment(appointment)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    titleEdit = new QLineEdit(this);
    descriptionEdit = new QLineEdit(this);
    locationEdit = new QLineEdit(this);
    startTimeEdit = new QDateTimeEdit(this);
    endTimeEdit = new QDateTimeEdit(this);

    titleEdit->setText(appointment.title);
    descriptionEdit->setText(appointment.description);
    locationEdit->setText(appointment.location);
    startTimeEdit->setDateTime(appointment.startTime);
    endTimeEdit->setDateTime(appointment.endTime);

    layout->addWidget(new QLabel("Title:", this));
    layout->addWidget(titleEdit);
    layout->addWidget(new QLabel("Description:", this));
    layout->addWidget(descriptionEdit);
    layout->addWidget(new QLabel("Location:", this));
    layout->addWidget(locationEdit);
    layout->addWidget(new QLabel("Start Time:", this));
    layout->addWidget(startTimeEdit);
    layout->addWidget(new QLabel("End Time:", this));
    layout->addWidget(endTimeEdit);

    saveButton = new QPushButton("Save", this);
    connect(saveButton, &QPushButton::clicked, this, &EditAppointmentDialog::onSaveButtonClicked);
    layout->addWidget(saveButton);

    setLayout(layout);
    setWindowTitle("Edit Appointment");
    resize(400, 300);
}

void EditAppointmentDialog::onSaveButtonClicked()
{
    appointment.title = titleEdit->text();
    appointment.description = descriptionEdit->text();
    appointment.location = locationEdit->text();
    appointment.startTime = startTimeEdit->dateTime();
    appointment.endTime = endTimeEdit->dateTime();

    accept();
}

void EditAppointmentDialog::setReadOnly(bool readOnly)
{
    titleEdit->setReadOnly(readOnly);
    descriptionEdit->setReadOnly(readOnly);
    locationEdit->setReadOnly(readOnly);
    startTimeEdit->setReadOnly(readOnly);
    endTimeEdit->setReadOnly(readOnly);
    saveButton->setVisible(!readOnly);
}
