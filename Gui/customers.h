#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QDialog>
#include <QPushButton>
#include <QTableWidget>
#include <QCommandLinkButton>
#include <QVector>
#include <QSignalMapper>
#include "customerservice.h"
#include "editcustomerdialog.h"

class Customers : public QDialog
{
    Q_OBJECT

public:
    explicit Customers(QWidget *parent = nullptr);
    ~Customers();

private slots:
    void onViewButtonClicked();
    void onEditButtonClicked();
    void onDeleteButtonClicked(int row);
    void onCommandLinkButtonClicked();

private:
    QTableWidget *tableWidget;
    QCommandLinkButton *commandLinkButton;
    QVector<bool> deletedRows;
    CustomerService *customerService;
    QSignalMapper *signalMapper;
    void setupTable();
    void loadJsonData();
    void addCustomerToJson(const QString &firstName, const QString &lastName, const QString &email, const QString &phoneNumber, const QString &address);
};

#endif // CUSTOMERS_H
