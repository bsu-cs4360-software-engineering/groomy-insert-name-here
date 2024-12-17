#ifndef SERVICESSERVICE_H
#define SERVICESSERVICE_H

#include <vector>
#include <QString>
#include "service.h"

class ServicesService {
public:
    ServicesService(const QString &filePath);

    std::vector<Service> getAllServices();
    Service getServiceById(int id);
    void createService(const Service &service);
    void updateService(const Service &service);
    void deleteService(int id);

private:
    QString filePath;
    std::vector<Service> loadServices();
    void saveServices(const std::vector<Service> &services);
};

#endif // SERVICESSERVICE
