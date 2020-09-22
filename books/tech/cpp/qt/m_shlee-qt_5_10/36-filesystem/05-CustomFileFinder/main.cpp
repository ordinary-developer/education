#include <QApplication>

#include "FileFinderWgt.hpp"


int main(int argc, char** argv) {
    QApplication app{ argc, argv };

    FileFinderWgt wgt{};
    wgt.resize(370, 240);
    wgt.show();

    return app.exec();
}
