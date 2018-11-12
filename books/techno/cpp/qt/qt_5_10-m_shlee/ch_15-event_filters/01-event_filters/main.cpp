#include "mouse_filt.hpp"
#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLineEdit lnEd{ "QLineEdit" };
    lnEd.installEventFilter(new MouseFilter{ &lnEd });
    lnEd.show();

    QLabel lbl{ "QLabel" };
    lbl.installEventFilter(new MouseFilter{ &lbl });
    lbl.show();

    QPushButton cmd{ "QPushButton" };
    cmd.installEventFilter(new MouseFilter{ &cmd });
    cmd.show();

    return app.exec();
}
