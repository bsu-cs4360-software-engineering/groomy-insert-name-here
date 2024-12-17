#ifndef APPOINTMENTSDIALOG_H
#define APPOINTMENTSDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <memory>
#include "appointmentservice.h"
#include "customerservice.h"
#include "appointment.h"

class AppointmentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppointmentsDialog(std::shared_ptr<AppointmentService> appointmentService, std::shared_ptr<CustomerService> customerService, QWidget *parent = nullptr);

private slots:
    void onAddButtonClicked();
    void onEditButtonClicked(int row);
    void onDeleteButtonClicked(int row);
    void onViewButtonClicked(int row);

private:
    std::shared_ptr<AppointmentService> appointmentService;
    std::shared_ptr<CustomerService> customerService;
    QTableWidget *tableAppointments;

    void loadAppointments();
    void addActionButtons(int row);
};

#endif // APPOINTMENTSDIALOG_H
