#ifndef INVOICE_H
#define INVOICE_H

#include <QWidget>

namespace Ui {
class Invoice;
}

class Invoice : public QWidget
{
    Q_OBJECT

public:
    explicit Invoice(QWidget *parent = nullptr);
    ~Invoice();

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::Invoice *ui;
};

#endif // INVOICE_H
