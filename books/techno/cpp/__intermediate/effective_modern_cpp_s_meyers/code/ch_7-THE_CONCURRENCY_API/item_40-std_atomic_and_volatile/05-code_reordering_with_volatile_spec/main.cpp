#include <atomic>

int computeImportantValue() { return 0; }

int main() {
    // can be reordred
    volatile bool valAvailable(false);
    auto imptValue = computeImportantValue();
    valAvailable = true;

    return 0;
}

