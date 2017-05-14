#include <QApplication>
#include "Calculator.h"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    Calculator calculator{};
    calculator.setWindowTitle("Calculator");
    calculator.resize(230, 220);
    calculator.show();

    return app.exec();
}
