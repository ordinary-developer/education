#include "SdiWnd.hpp"

#include <QApplication>
#include <QLabel>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    SdiWnd wnd{};
    wnd.setWindowTitle("sdi application");
    wnd.resize(300, 300);
    wnd.show();

    return app.exec();
}
