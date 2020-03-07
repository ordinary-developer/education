#include <QApplication>

#include <QtWidgets>


int main(int argc, char **argv) {
    QApplication app{argc, argv};
    
    QMenuBar menubar;
    QMenu *pMenu = new QMenu{"&Menu"};
    
    pMenu->addAction("&About Qt", &app, SLOT(aboutQt()), Qt::CTRL + Qt::Key_Q);
    pMenu->addSeparator();
    
    QAction *pCheckableAction = pMenu->addAction("&CheckableItem");
    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);
    
    QMenu *pSubmenu = new QMenu{"&Submenu", pMenu};
    pMenu->addMenu(pSubmenu);
    pSubmenu->addAction("&Test");
    
    QAction *pDisabledAction = pMenu->addAction("&DisabledItem");
    pDisabledAction->setEnabled(false);
    
    pMenu->addSeparator();
    
    pMenu->addAction("&Exit", &app, SLOT(quit()));
    
    menubar.addMenu(pMenu);
    menubar.show();
    
    return app.exec();
}