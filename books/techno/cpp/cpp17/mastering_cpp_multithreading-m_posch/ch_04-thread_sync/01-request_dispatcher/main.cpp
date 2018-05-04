#include "request.h"
#include "worker.h"
#include "dispatcher.h"

#include <iostream>
#include <string>
#include <csignal>
#include <mutex>
#include <thread>
#include <condition_variable>

std::sig_atomic_t signal_caught = 0;
std::mutex logMutex;

void sigint_handler(int sig) {
    signal_caught = 1;
}

void logFn(std::string const& text) {
    logMutex.lock();
    std::cout << text << "\n";
    logMutex.unlock();
}

int main() {
    signal(SIGINT, &sigint_handler);

    Dispatcher::init(10);
    std::cout << "Initialized.\n";

    int cycles = 0;
    Request* rq = nullptr;
    while (not signal_caught and cycles < 50) {
        rq = new Request();
        rq->setValue(cycles);
        rq->setOutput(&logFn);
        Dispatcher::addRequest(rq);
        ++cycles;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
    Dispatcher::stop();

    std::cout << "clean-up done" << std::endl;
    return 0;
}
