#include "ShellWgt.h"

#include <QApplication>
int main(int argc, char** argv) {
    QApplication app{argc, argv};
    
    ShellWgt shellWgt{};
    shellWgt.setWindowTitle("Command Shell");
    shellWgt.resize(320, 240);
    shellWgt.show();
    
    return app.exec();
}
