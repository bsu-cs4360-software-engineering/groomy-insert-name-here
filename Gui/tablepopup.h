#ifndef TABLEPOPUP_H
#define TABLEPOPUP_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>

class TablePopup : public QDialog
{
    Q_OBJECT

public:
    explicit TablePopup(QWidget *parent = nullptr);

signals:
    void saveCompleted();

private slots:
    void saveTableData();

private:
    QTableWidget *table;
    QPushButton *saveButton;
};

#endif // TABLEPOPUP_H
