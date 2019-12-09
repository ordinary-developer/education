#include <QtWidgets>

#include "ExampleWidget.hpp"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    ExampleWidget wgt{};
    wgt.resize(250, 130);
    wgt.show();
    
    return app.exec();
}