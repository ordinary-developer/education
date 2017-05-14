#include "Sender.hpp"
#include "Receiver.hpp"

int main() {
    Sender sender;
    Receiver receiver;

    QObject::connect(&sender, &Sender::signal,
                     &receiver, &Receiver::slot);

    sender.sendSignal();

    return 0;
}

