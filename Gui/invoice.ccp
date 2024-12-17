#include "invoice.h"
#include "ui_invoice.h"

Invoice::Invoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Invoice)
{
    ui->setupUi(this);
}

Invoice::~Invoice()
{
    delete ui;
}

void Invoice::on_comboBox_activated(int index)
{
    // Handle combo box activation
}
