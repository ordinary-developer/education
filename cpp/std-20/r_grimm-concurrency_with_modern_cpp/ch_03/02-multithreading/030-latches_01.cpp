#include <iostream>
#include <mutex>
#include <latch>
#include <thread>


std::latch gWorkDoneLatch(6);
std::latch gGoHomeLatch(1);

std::mutex gCoutMutex; 

void synchronizedOut(const std::string s) {
    std::lock_guard<std::mutex> _(gCoutMutex);
    std::cout << s;
}

class Worker {
public:
    Worker(std::string name) : name_(name) {}

    void operator()() {
        synchronizedOut("[ .... ] " + name_ + ": " + "Work done!\n");
        gWorkDoneLatch.count_down();

        gGoHomeLatch.wait();
        synchronizedOut("[ .... ] " + name_ + ": " + "Good bye!\n");
    }

private:
    std::string name_;
};


int main() {
    std::cout << "[ .... ] BOSS: START WORKING!" << std::endl;

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

    gWorkDoneLatch.wait();

    std::cout << "[ .... ] " << std::endl;

    
    std::cout << "[ .... ] BOSS: GO HOME!" << std::endl;
    gGoHomeLatch.count_down();

    herbWork.join();
    scottWork.join();
    bjarneWork.join();
    andreiWork.join();
    andrewWork.join();
    davidWork.join();
}
