#include "servicesview.h"
#include "notesdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include <QInputDialog>
#include <QHeaderView>

ServicesView::ServicesView(std::shared_ptr<ServicesService> servicesService, std::shared_ptr<NotesService> notesService, QWidget *parent)
    : QDialog(parent), servicesService(servicesService), notesService(notesService), signalMapper(new QSignalMapper(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    commandLinkButton = new QCommandLinkButton("Add Service", this);
    connect(commandLinkButton, &QCommandLinkButton::clicked, this, &ServicesView::onCommandLinkButtonClicked);
    layout->addWidget(commandLinkButton);

    QLabel *label = new QLabel("Services", this);
    layout->addWidget(label);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(5); // Add an extra column for actions
    tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "Description" << "Price" << "Actions");
    layout->addWidget(tableWidget);

    setupTable();

    setLayout(layout);
    setWindowTitle("Services");
    resize(800, 600);
}

void ServicesView::setupTable()
{
    loadJsonData();
    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Resize ID column to contents
    for (int i = 1; i < tableWidget->columnCount(); ++i) {
    tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

void ServicesView::loadJsonData()
{
    QFile file("services.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    if (document.isNull() || !document.isArray()) {
        qWarning() << "Invalid JSON format in file";
        return;
    }

    QJsonArray jsonArray = document.array();
    tableWidget->setRowCount(jsonArray.size());

    for (int row = 0; row < jsonArray.size(); ++row) {
        QJsonObject jsonObject = jsonArray.at(row).toObject();
        Service service = Service::fromJson(jsonObject);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(service.id)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(service.name));
        tableWidget->setItem(row, 2, new QTableWidgetItem(service.description));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString("$%1").arg(service.price, 0, 'f', 2)));
        addActionButtons(row);
    }
}

void ServicesView::addServiceToJson(const QString &name, const QString &description, double price)
{
    QFile file("services.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = document.array();

    int newId = jsonArray.size() + 1;
    Service newService(newId, name, description, price);
    jsonArray.append(newService.toJson());

    document.setArray(jsonArray);
    file.resize(0);
    file.write(document.toJson());
    file.close();

    loadJsonData();
}

void ServicesView::addActionButtons(int row)
{
    QWidget *actionWidget = new QWidget(this);
    QHBoxLayout *actionLayout = new QHBoxLayout(actionWidget);
    actionLayout->setContentsMargins(0, 0, 0, 0);

    QPushButton *viewButton = new QPushButton("View", actionWidget);
    QPushButton *editButton = new QPushButton("Edit", actionWidget);
    QPushButton *deleteButton = new QPushButton("Delete", actionWidget);
    QPushButton *notesButton = new QPushButton("Notes", actionWidget);

    connect(viewButton, &QPushButton::clicked, [this, row]() { onViewButtonClicked(row); });
    connect(editButton, &QPushButton::clicked, [this, row]() { onEditButtonClicked(row); });
    connect(deleteButton, &QPushButton::clicked, [this, row]() { onDeleteButtonClicked(row); });
    connect(notesButton, &QPushButton::clicked, [this, row]() { onNotesButtonClicked(row); });

    actionLayout->addWidget(viewButton);
    actionLayout->addWidget(editButton);
    actionLayout->addWidget(deleteButton);
    actionLayout->addWidget(notesButton);
    actionWidget->setLayout(actionLayout);

    tableWidget->setCellWidget(row, 4, actionWidget);
}

void ServicesView::onViewButtonClicked(int row)
{
    QString serviceDetails = QString("ID: %1\nName: %2\nDescription: %3\nPrice: %4")
    .arg(tableWidget->item(row, 0)->text())
        .arg(tableWidget->item(row, 1)->text())
        .arg(tableWidget->item(row, 2)->text())
        .arg(tableWidget->item(row, 3)->text());
    QMessageBox::information(this, "Service Details", serviceDetails);
}

void ServicesView::onEditButtonClicked(int row)
{
    bool ok;
    QString name = QInputDialog::getText(this, "Edit Name", "Name:", QLineEdit::Normal, tableWidget->item(row, 1)->text(), &ok);
    if (ok && !name.isEmpty()) {
        tableWidget->item(row, 1)->setText(name);
    }
    QString description = QInputDialog::getText(this, "Edit Description", "Description:", QLineEdit::Normal, tableWidget->item(row, 2)->text(), &ok);
    if (ok && !description.isEmpty()) {
        tableWidget->item(row, 2)->setText(description);
    }
    double price = QInputDialog::getDouble(this, "Edit Price", "Price:", tableWidget->item(row, 3)->text().toDouble(), 0, 1000000, 2, &ok);
    if (ok) {
        tableWidget->item(row, 3)->setText(QString::number(price));
    }

    // Update JSON file
    QFile file("services.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = document.array();

    QJsonObject jsonObject = jsonArray.at(row).toObject();
    jsonObject["name"] = name;
    jsonObject["description"] = description;
    jsonObject["price"] = price;

    jsonArray.replace(row, jsonObject);
    document.setArray(jsonArray);
    file.resize(0);
    file.write(document.toJson());
    file.close();
}

void ServicesView::onDeleteButtonClicked(int row)
{
    tableWidget->removeRow(row);

    // Update JSON file
    QFile file("services.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open file for writing:" << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray jsonArray = document.array();

    jsonArray.removeAt(row);
    document.setArray(jsonArray);
    file.resize(0);
    file.write(document.toJson());
    file.close();
}

void ServicesView::onNotesButtonClicked(int row)
{
    int serviceId = tableWidget->item(row, 0)->text().toInt();
    NotesDialog notesDialog(serviceId, notesService, this);
    notesDialog.exec();
}

void ServicesView::onCommandLinkButtonClicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Add Service", "Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        QString description = QInputDialog::getText(this, "Add Service", "Description:", QLineEdit::Normal, "", &ok);
        if (ok && !description.isEmpty()) {
            double price = QInputDialog::getDouble(this, "Add Service", "Price:", 0, 0, 1000000, 2, &ok);
            if (ok) {
                addServiceToJson(name, description, price);
            }
        }
    }
}
