#ifndef SERVICES_H
#define SERVICES_H

#include <QDialog>
#include <QTableWidget>
#include <QCommandLinkButton>
#include <QSignalMapper>
#include <QVector>
#include "servicesservice.h"
#include "noteservice.h"

class Services : public QDialog
{
    Q_OBJECT

public:
    explicit Services(QWidget *parent = nullptr);

private slots:
    void onViewButtonClicked(int row);
    void onEditButtonClicked(int row);
    void onDeleteButtonClicked(int row);
    void onNotesButtonClicked(int row);
    void onCommandLinkButtonClicked();

private:
    void setupTable();
    void loadJsonData();
    void addServiceToJson(const QString &name, const QString &description, double price);
    void addActionButtons(int row);

    QTableWidget *tableWidget;
    QCommandLinkButton *commandLinkButton;
    ServicesService *servicesService;
    std::shared_ptr<NotesService> notesService; // Declare notesService
    QSignalMapper *signalMapper;
    QVector<bool> deletedRows;

    // Add member variables to store service data
    QString name;
    QString description;
    double price;
};

#endif // SERVICES_H
