#ifndef VIEWCUSTOMERDIALOG_H
#define VIEWCUSTOMERDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

    class ViewCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCustomerDialog(const QJsonObject &customer, QWidget *parent = nullptr);

private:
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *emailLabel;
    QLabel *phoneNumberLabel;
    QLabel *addressLabel;
};

#endif // VIEWCUSTOMERDIALOG_H
