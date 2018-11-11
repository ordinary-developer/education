#include "multitouch_widget.hpp"
#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MultitouchWidget multitouchWgt{};

    multitouchWgt.resize(640, 480);
    multitouchWgt.show();

    return app.exec();
}
