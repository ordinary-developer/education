#include <QtCore>
#include <QtWidgets>
#include <QLabel>
#include "Counter.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QLabel lbl("0");
    QPushButton cmd("ADD");
    Counter counter;

    lbl.show();
    cmd.show();

                     

    QObject::connect(&cmd, &QPushButton::clicked, 
                     &counter, &Counter::slotInc);
    
    // here QLabel has overloaded "setNum" functions
    QObject::connect(&counter, &Counter::counterChanged,
      &lbl, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    QObject::connect(&counter, &Counter::goodbye,
            &app, &QApplication::quit);

    return app.exec();
}
