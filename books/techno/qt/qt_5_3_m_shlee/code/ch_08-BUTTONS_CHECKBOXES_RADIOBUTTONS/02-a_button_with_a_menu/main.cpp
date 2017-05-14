#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QPushButton button{"Menu"};
    QMenu* menu{ new QMenu(&button) };
    menu->addAction("Item1");
    menu->addAction("Item2");
    menu->addAction("&Quit", &app, &QApplication::quit);

    button.setMenu(menu);
    button.show();

    return app.exec();
}
