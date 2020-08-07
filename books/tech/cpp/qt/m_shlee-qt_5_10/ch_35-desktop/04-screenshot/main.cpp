#include "GrabWgt.hpp"

#include <QApplication>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    GrabWgt wgt{};
    wgt.show();

    return app.exec();
}
