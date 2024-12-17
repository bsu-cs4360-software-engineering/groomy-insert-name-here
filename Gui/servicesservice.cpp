#include "servicesservice.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

ServicesService::ServicesService(const QString &filePath)
    : filePath(filePath) {}

std::vector<Service> ServicesService::getAllServices() {
    return loadServices();
}

Service ServicesService::getServiceById(int id) {
    auto services = loadServices();
    for (const auto &service : services) {
        if (service.id == id) {
            return service;
        }
    }
    return Service();
}

void ServicesService::createService(const Service &service) {
    auto services = loadServices();
    services.push_back(service);
    saveServices(services);
}

void ServicesService::updateService(const Service &service) {
    auto services = loadServices();
    for (auto &s : services) {
        if (s.id == service.id) {
            s = service;
            break;
        }
    }
    saveServices(services);
}

void ServicesService::deleteService(int id) {
    auto services = loadServices();
    services.erase(std::remove_if(services.begin(), services.end(), [id](const Service &service) {
                       return service.id == id;
                   }), services.end());
    saveServices(services);
}

std::vector<Service> ServicesService::loadServices() {
    std::vector<Service> services;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << filePath;
        return services;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return services;
    }

    QJsonArray jsonArray = document.array();
    for (const auto &jsonValue : jsonArray) {
        services.push_back(Service::fromJson(jsonValue.toObject()));
    }

    return services;
}

void ServicesService::saveServices(const std::vector<Service> &services) {
    QJsonArray jsonArray;
    for (const auto &service : services) {
        jsonArray.append(service.toJson());
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
