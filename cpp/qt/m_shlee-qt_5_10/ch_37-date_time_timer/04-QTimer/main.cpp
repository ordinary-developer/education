#include "ClockWgt.h"

#include <QApplication>
int main(int argc, char** argv) {
    QApplication app{argc, argv};
    
    ClockWgt clockWgt{};
    clockWgt.show();
    
    return app.exec();
}
