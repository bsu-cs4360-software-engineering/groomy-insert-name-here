#ifndef APPOINTMENTSERVICE_H
#define APPOINTMENTSERVICE_H

#include <vector>
#include <QString>
#include <QJsonObject>
#include <QDateTime>
#include "appointment.h"

class AppointmentService {
public:
    AppointmentService(const QString &filePath);

    std::vector<Appointment> getAllAppointments();
    Appointment getAppointmentById(int id);
    void createAppointment(const Appointment &appointment);
    void updateAppointment(const Appointment &appointment);
    void deleteAppointment(int id);

private:
    QString filePath;
    std::vector<Appointment> loadAppointments();
    void saveAppointments(const std::vector<Appointment> &appointments);
    int generateNewId();
};

#endif // APPOINTMENTSERVICE_H
