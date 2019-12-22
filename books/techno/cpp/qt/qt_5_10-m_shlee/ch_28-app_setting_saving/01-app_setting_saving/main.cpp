#include <QApplication>
#include "MyPrgWgt.hpp"


int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    MyPrgWgt wgt{};
    wgt.show();
    
    return app.exec();
}
