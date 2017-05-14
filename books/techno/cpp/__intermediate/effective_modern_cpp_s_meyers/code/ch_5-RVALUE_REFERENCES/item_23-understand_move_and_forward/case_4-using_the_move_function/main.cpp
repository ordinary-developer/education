#include <memory>
#include <chrono>
#include <iostream>

// a dump class
class Widget { };

// a dump function
void process(const Widget& lvalArg) {
    std::cout << "Process(const Widget&) calling\n";
}

// a dump function
void process(const Widget&& rvalArg) {
    std::cout << "Process(Widget&& rvalArg)\n";
}

// a dump function
void makeLogEntry() { }

template<typename T>
void logAndProcess(T&& param) {
    auto now = 
        std::chrono::system_clock::now();
    makeLogEntry();
    process(std::forward<T>(param));
}

int main() {
    Widget w;

    logAndProcess(w);
    logAndProcess(std::move(w));

    return 0;
}

