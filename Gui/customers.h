#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QDialog>
#include <QTableWidget>
#include <QCommandLinkButton>
#include <QSignalMapper>
#include <QVector>
#include "customerservice.h"
#include "customer.h"

class Customers : public QDialog
{
    Q_OBJECT

public:
    explicit Customers(QWidget *parent = nullptr);

private slots:
    void onViewButtonClicked(int row);
    void onEditButtonClicked(int row);
    void onDeleteButtonClicked(int row);
    void onCommandLinkButtonClicked();

private:
    void setupTable();
    void loadJsonData();
    void addCustomerToJson(const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &address);
    void addActionButtons(int row);

    QTableWidget *tableWidget;
    QCommandLinkButton *commandLinkButton;
    CustomerService *customerService;
    QSignalMapper *signalMapper;
    QVector<bool> deletedRows;

    // Add member variables to store customer data
    QString firstName;
    QString lastName;
    QString email;
    QString phoneNumber;
    QString address;
};

#endif // CUSTOMERS_H
