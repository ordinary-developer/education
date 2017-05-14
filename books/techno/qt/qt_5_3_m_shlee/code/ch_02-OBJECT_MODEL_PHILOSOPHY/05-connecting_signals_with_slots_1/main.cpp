#include "Sender.hpp"
#include "Receiver.hpp"

#include <QtCore>

int main(int argc, char** argv) {
    Sender sender;
    Receiver receiver;

    QObject::connect(&sender, SIGNAL(signal()),
                     &receiver, SLOT(slot()));

    sender.sendSignal();

    return 0;
}
