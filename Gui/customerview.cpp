#include "customerview.h"
#include "editnoteview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

CustomerView::CustomerView(std::shared_ptr<CustomerService> customerService, std::shared_ptr<NotesService> notesService, QWidget *parent)
    : QDialog(parent), customerService(customerService), notesService(notesService)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Customers", this);
    layout->addWidget(label);

    tableCustomers = new QTableWidget(this);
    tableCustomers->setColumnCount(6);
    tableCustomers->setHorizontalHeaderLabels(QStringList() << "ID" << "First Name" << "Last Name" << "Email" << "Phone Number" << "Address");
    layout->addWidget(tableCustomers);

    connect(tableCustomers, &QTableWidget::itemSelectionChanged, this, &CustomerView::onCustomerSelected);

    QLabel *notesLabel = new QLabel("Notes", this);
    layout->addWidget(notesLabel);

    tableNotes = new QTableWidget(this);
    tableNotes->setColumnCount(4);
    tableNotes->setHorizontalHeaderLabels(QStringList() << "ID" << "Title" << "Data" << "Created Date");
    layout->addWidget(tableNotes);

    QPushButton *addNoteButton = new QPushButton("Add Note", this);
    connect(addNoteButton, &QPushButton::clicked, this, &CustomerView::onAddNoteButtonClicked);
    layout->addWidget(addNoteButton);

    loadCustomers();

    setLayout(layout);
    setWindowTitle("Customers");
    resize(800, 600);
}

void CustomerView::loadCustomers()
{
    qDebug() << "Loading customers...";
    std::vector<Customer> customers = customerService->getAllCustomers();
    tableCustomers->setRowCount(customers.size());

    for (std::size_t row = 0; row < customers.size(); ++row) {
        const Customer &customer = customers[row];
        qDebug() << "Processing customer:" << customer.id;
        tableCustomers->setItem(row, 0, new QTableWidgetItem(QString::number(customer.id)));
        tableCustomers->setItem(row, 1, new QTableWidgetItem(customer.firstName));
        tableCustomers->setItem(row, 2, new QTableWidgetItem(customer.lastName));
        tableCustomers->setItem(row, 3, new QTableWidgetItem(customer.email));
        tableCustomers->setItem(row, 4, new QTableWidgetItem(customer.phoneNumber));
        tableCustomers->setItem(row, 5, new QTableWidgetItem(customer.address));
    }
    qDebug() << "Finished loading customers.";
}

void CustomerView::loadNotes(int customerId)
{
    qDebug() << "Loading notes for customer ID:" << customerId;
    std::vector<Note> notes = notesService->getNotesByCustomerId(customerId);
    tableNotes->setRowCount(notes.size());

    for (std::size_t row = 0; row < notes.size(); ++row) {
        const Note &note = notes[row];
        qDebug() << "Processing note:" << note.id;
        tableNotes->setItem(row, 0, new QTableWidgetItem(QString::number(note.id)));
        tableNotes->setItem(row, 1, new QTableWidgetItem(note.title));
        tableNotes->setItem(row, 2, new QTableWidgetItem(note.data));
        tableNotes->setItem(row, 3, new QTableWidgetItem(note.createdDate.toString("yyyy-MM-dd HH:mm")));
    }
    qDebug() << "Finished loading notes.";
}

void CustomerView::onCustomerSelected()
{
    QList<QTableWidgetItem *> selectedItems = tableCustomers->selectedItems();
    if (!selectedItems.isEmpty()) {
        int customerId = selectedItems.first()->text().toInt();
        loadNotes(customerId);
    }
}

void CustomerView::onAddNoteButtonClicked()
{
    QList<QTableWidgetItem *> selectedItems = tableCustomers->selectedItems();
    if (!selectedItems.isEmpty()) {
        int customerId = selectedItems.first()->text().toInt();
        Note newNote;
        EditNoteView dialog(newNote, this);
        if (dialog.exec() == QDialog::Accepted) {
            notesService->createNoteForCustomer(newNote, customerId);
            loadNotes(customerId);
        }
    }
}
