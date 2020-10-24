#include <QApplication>
#include "Widget.hpp"

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    Widget wgt1{};
    wgt1.setWindowTitle("widget1");
    wgt1.setObjectName("widget1");
    wgt1.resize(200, 200);
    wgt1.show();

    Widget wgt2{};
    wgt2.setWindowTitle("widget2");
    wgt2.setObjectName("widget2");
    wgt2.resize(200, 200);
    wgt2.show();

    return app.exec();
}
