#include "SysTray.hpp"

#include <QApplication>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    SysTray sysTray{};
    QApplication::setQuitOnLastWindowClosed(false);

    return app.exec();
}