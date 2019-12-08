#include <QtWidgets>

#include "MouseWheelObserver.hpp"


int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    MouseWheelObserver wgt{};
    wgt.resize(250, 130);
    wgt.show();
    
    return app.exec();
}
