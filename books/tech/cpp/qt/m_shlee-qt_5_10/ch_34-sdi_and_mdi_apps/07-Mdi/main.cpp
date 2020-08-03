#include "MdiWnd.hpp"

#include <QApplication>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    MdiWnd wnd{};
    wnd.setWindowTitle("Mdi Program");
    wnd.show();

    return app.exec();
}