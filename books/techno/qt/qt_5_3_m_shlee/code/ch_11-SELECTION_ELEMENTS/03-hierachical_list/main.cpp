#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QTreeWidget treeWidget{};
    QStringList stringList;

    stringList << "Folders" << "Used Space";
    treeWidget.setHeaderLabels(stringList);
    treeWidget.setSortingEnabled(true);

    QTreeWidgetItem* pTreeWidgetItem{ new QTreeWidgetItem{&treeWidget} };
    pTreeWidgetItem->setText(0, "Local Disk(C)");
    pTreeWidgetItem->setIcon(0, QPixmap{ ":/drive.jpg" });

    QTreeWidgetItem* pTreeWidgetItemDir{ nullptr };
    for (int i{1}; i < 20; ++i) {
        pTreeWidgetItemDir = new QTreeWidgetItem{ pTreeWidgetItem };
        pTreeWidgetItemDir->setText(0, "Directory" + QString::number(i));
        pTreeWidgetItemDir->setText(1, QString::number(i) + " MB");
        pTreeWidgetItemDir->setIcon(0, QPixmap{ ":/folder.jpg" });
    }

    treeWidget.setItemExpanded(pTreeWidgetItem, true);
    treeWidget.resize(250, 110);
    treeWidget.show();

    return app.exec();
}
