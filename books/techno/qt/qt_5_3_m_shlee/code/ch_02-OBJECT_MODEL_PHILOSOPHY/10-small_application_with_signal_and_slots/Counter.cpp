#include "Counter.hpp"

Counter::Counter() : QObject(), _value(0) { }

void Counter::slotInc() {
    emit counterChanged(++_value);

    if (5 == _value) {
        emit goodbye();
    }
}
