#include "StartDlg.hpp"

#include <QApplication>


int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    StartDlg startDlg{};
    startDlg.show();
    
    return app.exec();
}
