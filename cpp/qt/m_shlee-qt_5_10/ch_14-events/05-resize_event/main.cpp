#include <QApplication>

#include "ResizeObserver.hpp"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    ResizeObserver wgt{};
    wgt.resize(250, 130);
    wgt.show();
    
    return app.exec();
}
