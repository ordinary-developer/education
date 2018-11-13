#include "key_filter.hpp"
#include <QtWidgets>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    QLineEdit lineEdit{};
    lineEdit.show();

    KeyFilter* pFilter = new KeyFilter(&lineEdit);
    lineEdit.installEventFilter(pFilter);

    return app.exec();
}
