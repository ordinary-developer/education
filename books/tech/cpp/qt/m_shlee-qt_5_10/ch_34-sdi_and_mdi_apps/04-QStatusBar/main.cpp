#include "MainWindow.hpp"

#include <QApplication>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MainWindow mainWnd{};
    mainWnd.resize(235, 180);
    mainWnd.show();

    return app.exec();
}
