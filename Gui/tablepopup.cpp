#include "tablepopup.h"
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QMessageBox>

TablePopup::TablePopup(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("New user account");
    setGeometry(600, 600, 500, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);

    table = new QTableWidget(this);
    table->setRowCount(1);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"First name", "Last name", "Email address", "password"});

    QList<QList<QString>> data = {
        {"", "", "","" },

    };

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < data[row].size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(data[row][col]);
            item->setForeground(QBrush(QColor("#000FF")));
            table->setItem(row, col, item);

        }
    }
    saveButton = new QPushButton("Save", this);
    connect(saveButton, &QPushButton::clicked, this, &TablePopup::saveTableData);

    layout->addWidget(table);
    layout->addWidget(saveButton);

    this->setStyleSheet("background-color: rgb(106,106,106);");  // Background color for the dialog
    table->setStyleSheet("QTableWidget { background-color: rgb(106,106,106); gridline-color: rgb(0,0,225); }"
                         "QHeaderView::section { background-color: rgb(0,0,225); }");
}

void TablePopup::saveTableData()
{
    // Implement your save logic here
    QMessageBox::information(this, "Save", "Table data saved successfully!");
    emit saveCompleted();  // Emit the signal to notify that save is completed
    this->accept();  // Close the dialog
}
