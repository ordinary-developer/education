#include <QtWidgets>

#include "int_list_model.hpp"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    IntListModel model(QList<int>() << 123 << 2341 << 32 << 5342 << 723);

    QListView list{};
    list.setModel(&model);
    list.show();

    QTableView table{};
    table.setModel(&model);
    table.show();

    return app.exec();
}
