#include "MainWindow.hpp"

#include <QApplication>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MainWindow mainWnd{};
    mainWnd.resize(210, 210);
    mainWnd.show();

    return app.exec();
}