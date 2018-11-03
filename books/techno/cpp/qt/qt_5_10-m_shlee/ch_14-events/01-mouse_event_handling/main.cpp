#include "mouse_observer.hpp"

#include <QtWidgets>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MouseObserver widget{};

    widget.resize(250, 130);
    widget.show();

    return app.exec();
}

