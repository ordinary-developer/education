#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QStringList stringList{};
    QListWidget listWidget{};
    QListWidgetItem* pListWidgetItem{nullptr};

    listWidget.setIconSize(QSize{48, 48});
    stringList << "linux" << "windows" << "macosx" << "android";
    foreach (QString str, stringList) {
        pListWidgetItem = new QListWidgetItem(str, &listWidget);
        pListWidgetItem->setIcon(QPixmap(":/" + str + ".jpg"));
    }
    listWidget.resize(125, 175);
    listWidget.show();

    return app.exec();
}
