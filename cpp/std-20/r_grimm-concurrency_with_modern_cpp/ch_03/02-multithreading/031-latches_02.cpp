#include <iostream>
#include <latch>
#include <mutex>
#include <thread>


std::latch workDone(6);
std::mutex coutMutex;

void synchronizedOut(const std::string& s) {
    std::lock_guard<std::mutex> _(coutMutex);
    std::cout << s;
}

class Worker {
public:
    Worker(std::string name) : name_(name) {};

    void operator() () {
        synchronizedOut(name_ + ": " + "Work done!\n");
        workDone.arrive_and_wait();
        synchronizedOut(name_ + ": " + "See you tomorrow!\n");
    }

private:
    std::string name_;
};


int main() {
    std::cout << '\n';

    Worker herb("  Herb");
    std::thread herbWork(herb);

    Worker scott("    Scott");
    std::thread scottWork(scott);

    Worker bjarne("      Bjarne");
    std::thread bjarneWork(bjarne);

    Worker andrei("        Andrei");
    std::thread andreiWork(andrei);

    Worker andrew("          Andrew");
    std::thread andrewWork(andrew);

    Worker david("            David");
    std::thread davidWork(david);

    herbWork.join();
    scottWork.join();
    bjarneWork.join();
    andreiWork.join();
    andrewWork.join();
    davidWork.join();
}