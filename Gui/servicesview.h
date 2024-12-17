#ifndef SERVICESVIEW_H
#define SERVICESVIEW_H

#include <QDialog>
#include <QTableWidget>
#include <QCommandLinkButton>
#include <QSignalMapper>
#include <QVector>
#include "servicesservice.h"
#include "noteservice.h"

class ServicesView : public QDialog
{
    Q_OBJECT

public:
    explicit ServicesView(std::shared_ptr<ServicesService> servicesService, std::shared_ptr<NotesService> notesService, QWidget *parent = nullptr);

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
    std::shared_ptr<ServicesService> servicesService;
    std::shared_ptr<NotesService> notesService;
    QSignalMapper *signalMapper;
    QVector<bool> deletedRows;

    // Add member variables to store service data
    QString name;
    QString description;
    double price;
};

#endif // SERVICESVIEW_H
