#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    const int n{3};

    QTableWidget tableWidget{n, n};
    QTableWidgetItem* pTableWidgetItem{nullptr};
    QStringList stringList{};

    stringList << "First" << "Second" << "Third";
    tableWidget.setHorizontalHeaderLabels(stringList);
    tableWidget.setVerticalHeaderLabels(stringList);

    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
            pTableWidgetItem = 
                new QTableWidgetItem{ QString{"%1,%2"}.arg(i).arg(j) };
            tableWidget.setItem(i, j, pTableWidgetItem);
        }
    }

    tableWidget.resize(370, 135);
    tableWidget.show();

    return app.exec();
}
