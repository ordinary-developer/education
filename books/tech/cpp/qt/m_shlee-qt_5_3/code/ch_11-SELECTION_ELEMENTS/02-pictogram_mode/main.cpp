#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QListWidget listWidget{};
    QListWidgetItem* pListWidgetItem{ nullptr };
    QStringList stringList{};

    listWidget.setIconSize(QSize{48, 48});
    listWidget.setSelectionMode(QAbstractItemView::MultiSelection);
    listWidget.setViewMode(QListView::IconMode);
    stringList << "linux" << "windows" << "macosx" << "android";
    foreach (QString str, stringList) {
        pListWidgetItem = new QListWidgetItem(str, &listWidget);
        pListWidgetItem->setIcon(QPixmap{":/" + str + ".jpg"});
        pListWidgetItem->setFlags(Qt::ItemIsEnabled    | 
                                  Qt::ItemIsSelectable |
                                  Qt::ItemIsEditable   |
                                  Qt::ItemIsDragEnabled);
    }

    listWidget.resize(150, 150);
    listWidget.show();

    return app.exec();
}
