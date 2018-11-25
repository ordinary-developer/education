#include <QApplication>
#include "Drop.hpp"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    Drop drop{};
    drop.resize(150, 150);
    drop.show();

    return app.exec();
}

