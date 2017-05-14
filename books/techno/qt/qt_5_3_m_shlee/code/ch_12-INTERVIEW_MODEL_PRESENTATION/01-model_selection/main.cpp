#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    // Model setup
    QStringListModel model{};
    model.setStringList(QStringList{} << "Item1" << "Item2" << "Item3");

    QTreeView* pTreeView{ new QTreeView{} };
    pTreeView->setModel(&model);

    QListView* pListView{ new QListView{} };
    pListView->setModel(&model);

    QTableView* pTableView{ new QTableView{} };
    pTableView->setModel(&model);

    QItemSelectionModel selection{ &model };
    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);

    // Layout setup
    QWidget widget{};

    QHBoxLayout* pHBoxLayout{ new QHBoxLayout{} };
    pHBoxLayout->addWidget(pTreeView);
    pHBoxLayout->addWidget(pListView);
    pHBoxLayout->addWidget(pTableView);
    widget.setLayout(pHBoxLayout);

    widget.show();

    return app.exec();
}
