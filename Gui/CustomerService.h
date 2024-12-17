#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include <vector>
#include <QString>
#include "customer.h"

class CustomerService {
public:
    CustomerService(const QString &filePath); // Constructor with file path

    std::vector<Customer> getAllCustomers();
    Customer getCustomerById(int id);
    void createCustomer(const Customer &customer);
    void updateCustomer(const Customer &customer);
    void deleteCustomer(int id);

private:
    QString filePath;
    std::vector<Customer> loadCustomers();
    void saveCustomers(const std::vector<Customer> &customers); // Correct declaration
};

#endif // CUSTOMERSERVICE_
