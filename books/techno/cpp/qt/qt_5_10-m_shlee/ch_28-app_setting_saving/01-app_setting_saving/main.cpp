#include "MyProgram.hpp"

#include <QApplication>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MyProgram myProgram{};
    myProgram.show();
    
    return app.exec();
}
