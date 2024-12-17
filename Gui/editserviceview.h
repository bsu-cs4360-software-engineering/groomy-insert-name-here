#ifndef EDITSERVICEVIEW_H
#define EDITSERVICEVIEW_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include "service.h"

    class EditServiceView : public QDialog
{
    Q_OBJECT

public:
    explicit EditServiceView(Service &service, QWidget *parent = nullptr);

private slots:
    void onSaveButtonClicked();

private:
    void populateForm(const Service &service);

    Service &service;
    QLineEdit *nameEdit;
    QTextEdit *descriptionEdit;
    QLineEdit *priceEdit;
    QPushButton *saveButton;
};

#endif // EDITSERVICEVIEW_H
