#ifndef EDITAPPOINTMENTDIALOG_H
#define EDITAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateTimeEdit>
#include "appointment.h"

class EditAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditAppointmentDialog(Appointment &appointment, QWidget *parent = nullptr);
    void setReadOnly(bool readOnly);

private slots:
    void onSaveButtonClicked();

private:
    Appointment &appointment;
    QLineEdit *titleEdit;
    QLineEdit *descriptionEdit;
    QLineEdit *locationEdit;
    QDateTimeEdit *startTimeEdit;
    QDateTimeEdit *endTimeEdit;
    QPushButton *saveButton;
};

#endif // EDITAPPOINTMENTDIALOG_H
