#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QSplitter spl(Qt::Horizontal);
    QFileSystemModel model{};

    model.setRootPath(QDir::rootPath());

    QTreeView* pTreeView{ new QTreeView };
    pTreeView->setModel(&model);

    QTableView* pTableView{ new QTableView };
    pTableView->setModel(&model);

    //QObject::connect(pTreeView,
    //                 SIGNAL(clicked(QModelIndex const&)),
    //                 pTableView,
    //                 SLOT(setRootIndex(QModelIndex const&)));
    QObject::connect(pTreeView,
                     &QTreeView::clicked,
                     pTableView,
                     &QTableView::setRootIndex);

    //QObject::connect(pTableView,
    //                 SIGNAL(activated(QModelIndex const&)),
    //                 pTreeView,
    //                 SLOT(setCurrentIndex(QModelIndex const&)));
    QObject::connect(pTableView,
                     &QTableView::activated,
                     pTreeView,
                     &QTreeView::setCurrentIndex);

    //QObject::connect(pTableView,
    //                 SIGNAL(activated(QModelIndex const&)),
    //                 pTableView,
    //                 SLOT(setRootIndex(QModelIndex const&)));
    QObject::connect(pTableView,
                     &QTableView::activated,
                     pTableView,
                     &QTableView::setRootIndex);

    spl.addWidget(pTreeView);
    spl.addWidget(pTableView);
    spl.show();

    return app.exec();
}
