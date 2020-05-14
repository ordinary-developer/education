#include <atomic>

int computeImportantValue() { return 0; }

int main() {
    // can't be reordred
    std::atomic<bool> valAvailable(false);
    auto imptValue = computeImportantValue();
    valAvailable = true;

    return 0;
}

