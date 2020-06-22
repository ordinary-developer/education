#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QStringList list{};
    list << "linux" << "windows" << "macos" << "os2";

    QStandardItemModel model(list.size(), 1);
    for (int i{0}; i < model.rowCount(); ++i) {
        QModelIndex index{ model.index(i, 0) };
        QString str = list.at(i);
        model.setData(index, str, Qt::DisplayRole);
        model.setData(index, "ToolTip for " + str, Qt::ToolTipRole);
        model.setData(index, 
                      QIcon("img/" + str + ".jpg"), 
                      Qt::DecorationRole);
    }

    QListView listView{};
    listView.setViewMode(QListView::IconMode);
    listView.setModel(&model);
    listView.show();

    return app.exec();
}
