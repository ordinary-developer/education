#include "Sender.hpp"
#include "Receiver.hpp"

#include <QtCore>

int main() {
    bool bOk = true;

    Sender sender1;
    Receiver receiver1;

    bOk &= QObject::connect(&sender1, SIGNAL(signal()),
                     &receiver1, SLOT(slot()));

    Sender sender2;
    Receiver receiver2;

    bOk &= QObject::connect(&sender2, SIGNAL(signal()),
                            &receiver2, SLOT(slot()));
    Q_ASSERT(bOk);

    sender1.sendSignal();
    sender2.sendSignal();

    return 0;
}

