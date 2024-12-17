#include "appointmentservice.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

AppointmentService::AppointmentService(const QString &filePath)
    : filePath(filePath) {}

std::vector<Appointment> AppointmentService::getAllAppointments() {
    return loadAppointments();
}

Appointment AppointmentService::getAppointmentById(int id) {
    auto appointments = loadAppointments();
    for (const auto &appointment : appointments) {
        if (appointment.id == id) {
            return appointment;
        }
    }
    return Appointment();
}

void AppointmentService::createAppointment(const Appointment &appointment) {
    auto appointments = loadAppointments();
    Appointment newAppointment = appointment;
    newAppointment.id = generateNewId();
    appointments.push_back(appointment);
    saveAppointments(appointments);
}

void AppointmentService::updateAppointment(const Appointment &appointment) {
    auto appointments = loadAppointments();
    for (auto &a : appointments) {
        if (a.id == appointment.id) {
            a = appointment;
            break;
        }
    }
    saveAppointments(appointments);
}

void AppointmentService::deleteAppointment(int id) {
    auto appointments = loadAppointments();
    appointments.erase(std::remove_if(appointments.begin(), appointments.end(), [id](const Appointment &appointment) {
                           return appointment.id == id;
                       }), appointments.end());
    saveAppointments(appointments);
}

std::vector<Appointment> AppointmentService::loadAppointments() {
    std::vector<Appointment> appointments;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << filePath;
        return appointments;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return appointments;
    }

    QJsonArray jsonArray = document.array();
    for (const auto &jsonValue : jsonArray) {
        appointments.push_back(Appointment::fromJson(jsonValue.toObject()));
    }

    return appointments;
}

void AppointmentService::saveAppointments(const std::vector<Appointment> &appointments) {
    QJsonArray jsonArray;
    for (const auto &appointment : appointments) {
        jsonArray.append(appointment.toJson());
    }

    QJsonDocument document(jsonArray);
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << filePath;
        return;
    }

    file.write(document.toJson());
    file.close();
}
int AppointmentService::generateNewId() {
    auto appointments = loadAppointments();
    if (appointments.empty()) {
        return 1; // First appointment ID should be 1
    }
    int maxId = 0;
    for (const auto &appointment : appointments) {
        if (appointment.id > maxId) {
            maxId = appointment.id;
        }
    }
    return maxId + 1;
}
