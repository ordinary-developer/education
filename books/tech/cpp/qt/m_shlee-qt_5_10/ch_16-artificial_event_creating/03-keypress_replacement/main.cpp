#include "KeyFilter.hpp"

#include <QApplication>
#include <QLineEdit>


int main(int argc, char **argv) {
    QApplication app{ argc, argv };
    
    QLineEdit txt{};
    txt.show();
    
    KeyFilter* pFilter = new KeyFilter(&txt);
    txt.installEventFilter(pFilter);
    
    return app.exec();
}
