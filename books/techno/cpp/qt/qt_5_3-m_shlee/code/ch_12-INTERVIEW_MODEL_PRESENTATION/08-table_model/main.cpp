#include <QtWidgets>

#include "table_model.hpp"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    TableModel model{ 200, 200 };
    QTableView tableView{};
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}
