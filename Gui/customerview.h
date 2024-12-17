#ifndef CUSTOMERVIEW_H
#define CUSTOMERVIEW_H

#include <QDialog>
#include <QTableWidget>
#include <memory>
#include "customerservice.h"
#include "noteservice.h"

    class CustomerView : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerView(std::shared_ptr<CustomerService> customerService, std::shared_ptr<NotesService> notesService, QWidget *parent = nullptr);

private slots:
    void onCustomerSelected();
    void onAddNoteButtonClicked();

private:
    std::shared_ptr<CustomerService> customerService;
    std::shared_ptr<NotesService> notesService;
    QTableWidget *tableCustomers;
    QTableWidget *tableNotes;

    void loadCustomers();
    void loadNotes(int customerId);
};

#endif // CUSTOMERVIEW_H
