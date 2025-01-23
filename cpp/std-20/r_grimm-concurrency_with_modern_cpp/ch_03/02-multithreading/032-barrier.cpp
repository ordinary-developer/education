#include <iostream>
#include <barrier>
#include <mutex>
#include <string>
#include <thread>


std::barrier gWorkDoneBarrier(6);
std::mutex gCoutMutex;

void synchronizedOut(const std::string & s) noexcept {
    std::lock_guard<std::mutex> _(gCoutMutex);
    std::cout << s;
}

class FullTimeWorker {
public:
    FullTimeWorker(std::string name) : name_(name) {};

    void operator()() {
        synchronizedOut("[ .... ]" + name_ + ": Morning work has been done\n");
        gWorkDoneBarrier.arrive_and_wait();
        synchronizedOut("[ .... ]" + name_ + ": Afternoon work has been done\n");
        gWorkDoneBarrier.arrive_and_wait();
    }
private:
    std::string name_;    
};

class PartTimeWorker {
public:
    PartTimeWorker(std::string name) : name_(name) { };

    void operator()() {
        synchronizedOut("[ .... ]" + name_ + ": Morning work done\n");
        gWorkDoneBarrier.arrive_and_drop();
    }
private:
    std::string name_;
};


int main() {
    FullTimeWorker herb("  Herb");
    std::thread herbWork(herb);

    FullTimeWorker scott("    Scott");
    std::thread scottWork(scott);

    FullTimeWorker bjarne("      Bjarne");
    std::thread bjarneWork(bjarne);

    PartTimeWorker andrei("        Andrei");
    std::thread andreiWork(andrei);

    PartTimeWorker andrew("          Andrew");
    std::thread andrewWork(andrew);

    PartTimeWorker david("            David");
    std::thread davidWork(david);

    herbWork.join();
    scottWork.join();
    bjarneWork.join();
    andreiWork.join();
    andrewWork.join();
    davidWork.join();
}
