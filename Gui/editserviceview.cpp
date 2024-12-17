#include "editserviceview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

EditServiceView::EditServiceView(Service &service, QWidget *parent)
    : QDialog(parent), service(service)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    nameEdit = new QLineEdit(this);
    descriptionEdit = new QTextEdit(this);
    priceEdit = new QLineEdit(this);

    populateForm(service);

    layout->addWidget(new QLabel("Name:", this));
    layout->addWidget(nameEdit);
    layout->addWidget(new QLabel("Description:", this));
    layout->addWidget(descriptionEdit);
    layout->addWidget(new QLabel("Price:", this));
    layout->addWidget(priceEdit);

    saveButton = new QPushButton("Save", this);
    connect(saveButton, &QPushButton::clicked, this, &EditServiceView::onSaveButtonClicked);
    layout->addWidget(saveButton);

    setLayout(layout);
    setWindowTitle("Edit Service");
    resize(800, 600);
}

void EditServiceView::populateForm(const Service &service)
{
    nameEdit->setText(service.name);
    descriptionEdit->setText(service.description);
    priceEdit->setText(QString::number(service.price));
}

void EditServiceView::onSaveButtonClicked()
{
    service.name = nameEdit->text();
    service.description = descriptionEdit->toPlainText();
    service.price = priceEdit->text().toDouble();

    accept();
}
