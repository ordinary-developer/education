#include <QApplication>
#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QMenuBar menuBar{};

    QMenu *pMenu{ new QMenu{ "&menu" } };
    pMenu->addAction("&about qt", 
        &app, &QApplication::aboutQt,
        Qt::CTRL + Qt::Key_Q);
    pMenu->addSeparator();

    QAction *pCheckableAction = pMenu->addAction("&checkable_item");
    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);

    pMenu->addAction(QPixmap{ ":/img.jpg" }, "&icon_item");

    QMenu *pSubmenu{ new QMenu{ "&submenu", pMenu } };
    pMenu->addMenu(pSubmenu);
    pSubmenu->addAction("&test");

    QAction *pDisabledAction = pMenu->addAction("&disabled_item");
    pDisabledAction->setEnabled(false);

    pMenu->addSeparator();
    pMenu->addAction("&exit", &app, &QApplication::quit);

    menuBar.addMenu(pMenu);
    menuBar.show();

    return app.exec();
}
