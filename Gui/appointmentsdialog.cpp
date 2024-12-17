#include "appointmentsdialog.h"
#include "editappointmentdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QHeaderView>

AppointmentsDialog::AppointmentsDialog(std::shared_ptr<AppointmentService> appointmentService, std::shared_ptr<CustomerService> customerService, QWidget *parent)
    : QDialog(parent), appointmentService(appointmentService), customerService(customerService)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("Add Appointment", this);

    connect(addButton, &QPushButton::clicked, this, &AppointmentsDialog::onAddButtonClicked);

    buttonLayout->addWidget(addButton);
    layout->addLayout(buttonLayout);

    QLabel *label = new QLabel("Appointments", this);
    layout->addWidget(label);

    tableAppointments = new QTableWidget(this);
    tableAppointments->setColumnCount(7);
    tableAppointments->setHorizontalHeaderLabels(QStringList() << "ID" << "Title" << "Description" << "Location" << "Start Time" << "End Time" << "Actions");
    tableAppointments->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Resize ID column to contents
    for (int i = 1; i < tableAppointments->columnCount(); ++i) {
        tableAppointments->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    layout->addWidget(tableAppointments);

    loadAppointments();

    setLayout(layout);
    setWindowTitle("Appointments");
    resize(1000, 600);

}

void AppointmentsDialog::loadAppointments()
{
    qDebug() << "Loading appointments...";
    std::vector<Appointment> appointments = appointmentService->getAllAppointments();
    tableAppointments->setRowCount(appointments.size());

    for (std::size_t row = 0; row < appointments.size(); ++row) {
        const Appointment &appointment = appointments[row];
        qDebug() << "Processing appointment:" << appointment.id;
        tableAppointments->setItem(row, 0, new QTableWidgetItem(QString::number(appointment.id)));
        tableAppointments->setItem(row, 1, new QTableWidgetItem(appointment.title));
        tableAppointments->setItem(row, 2, new QTableWidgetItem(appointment.description));
        tableAppointments->setItem(row, 3, new QTableWidgetItem(appointment.location));
        tableAppointments->setItem(row, 4, new QTableWidgetItem(appointment.startTime.toString("yyyy-MM-dd HH:mm")));
        tableAppointments->setItem(row, 5, new QTableWidgetItem(appointment.endTime.toString("yyyy-MM-dd HH:mm")));
        addActionButtons(row);
    }
    qDebug() << "Finished loading appointments.";
}

void AppointmentsDialog::addActionButtons(int row)
{
    QWidget *actionWidget = new QWidget(this);
    QHBoxLayout *actionLayout = new QHBoxLayout(actionWidget);
    actionLayout->setContentsMargins(0, 0, 0, 0);

    QPushButton *viewButton = new QPushButton("View", actionWidget);
    QPushButton *editButton = new QPushButton("Edit", actionWidget);
    QPushButton *deleteButton = new QPushButton("Delete", actionWidget);

    connect(viewButton, &QPushButton::clicked, [this, row]() { onViewButtonClicked(row); });
    connect(editButton, &QPushButton::clicked, [this, row]() { onEditButtonClicked(row); });
    connect(deleteButton, &QPushButton::clicked, [this, row]() { onDeleteButtonClicked(row); });

    actionLayout->addWidget(viewButton);
    actionLayout->addWidget(editButton);
    actionLayout->addWidget(deleteButton);
    actionWidget->setLayout(actionLayout);

    tableAppointments->setCellWidget(row, 6, actionWidget);
}

void AppointmentsDialog::onAddButtonClicked()
{
    Appointment newAppointment;
    EditAppointmentDialog dialog(newAppointment, this);
    if (dialog.exec() == QDialog::Accepted) {
        appointmentService->createAppointment(newAppointment);
        loadAppointments();
    }
}

void AppointmentsDialog::onEditButtonClicked(int row)
{
    int id = tableAppointments->item(row, 0)->text().toInt();
    Appointment appointment = appointmentService->getAppointmentById(id);
    EditAppointmentDialog dialog(appointment, this);
    if (dialog.exec() == QDialog::Accepted) {
        appointmentService->updateAppointment(appointment);
        loadAppointments();
    }
}

void AppointmentsDialog::onDeleteButtonClicked(int row)
{
    int id = tableAppointments->item(row, 0)->text().toInt();
    appointmentService->deleteAppointment(id);
    loadAppointments();
}

void AppointmentsDialog::onViewButtonClicked(int row)
{
    int id = tableAppointments->item(row, 0)->text().toInt();
    Appointment appointment = appointmentService->getAppointmentById(id);
    EditAppointmentDialog dialog(appointment, this);
    dialog.setWindowTitle("View Appointment");
    dialog.setReadOnly(true);
    dialog.exec();
}
