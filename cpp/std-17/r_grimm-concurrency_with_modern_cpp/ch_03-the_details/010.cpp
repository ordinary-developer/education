#include <atomic>
#include <iostream>
#include <string>
#include <thread>


std::string work{};
std::atomic<bool> ready{false};

void consumer() {
    while (not ready.load()) {}
    std::cout << work << std::endl;
}

void producer() {
    work = "done";
    ready = true;
}


int main(){
    std::thread prod{producer}, con{consumer};
    if (prod.joinable())
        prod.join();

    if (con.joinable())
        con.join();
}
