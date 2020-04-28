#include <QApplication>
#include <QtWidgets>

#include "context_menu_widget.hpp"

int main(int argc, char **argv) {
    QApplication app{ argc, argv };

    ContextMenuWidget wgt{};

    wgt.resize(200, 200);
    wgt.show();

    return app.exec();
}
