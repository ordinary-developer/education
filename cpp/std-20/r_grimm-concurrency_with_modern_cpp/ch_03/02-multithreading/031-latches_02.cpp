#include <iostream>
#include <latch>
#include <mutex>
#include <thread>


std::latch gWorkDoneLatch(6);
std::mutex gCoutMutex;

void synchronizedOut(const std::string & s) {
    std::lock_guard<std::mutex> _(gCoutMutex);
    std::cout << s;
}

class Worker {
public:
    Worker(std::string name) : name_(name) {};

    void operator()() {
        synchronizedOut("[ .... ]" + name_ + ": Work done!\n");
        gWorkDoneLatch.arrive_and_wait();
        synchronizedOut("[ .... ]" + name_ + ": see you tomorrow!\n");
    }

private:
    std::string name_;
};


int main() {
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
