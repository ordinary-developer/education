#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>


std::vector<int> gMyVec{};

std::counting_semaphore<1> gPrepareSignal(0);

void prepareWork() {
    gMyVec.insert(gMyVec.end(), { 0, 1, 0, 3});
    std::cout << "[ .... ] sender: data have been prepared" << std::endl;
    gPrepareSignal.release();
    std::cout << "[ .... ] sender: the signal has been sent" << std::endl;
}

void completeWork() {
    std::cout << "[ .... ] waiter: waiting for data" << std::endl;
    gPrepareSignal.acquire();
    gMyVec[2] = 2;
    std::cout << "[ .... ] waiter: complete the work, values = ";
    for (auto i : gMyVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::thread t1(prepareWork);
    std::thread t2(completeWork);
    t1.join();
    t2.join();

    std::cout << std::endl;
}
