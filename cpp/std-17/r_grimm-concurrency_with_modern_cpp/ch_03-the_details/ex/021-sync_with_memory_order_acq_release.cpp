#include <atomic>
#include <iostream>
#include <string>
#include <thread>

std::string work;
std::atomic<bool> ready(false);

void consumer() {
    while (not ready.load()) {
        (void)(0);
    }
    std::cout << work << '\n';
}

void producer() {
    work = "done";
    ready = true;
}

int main()
{
    std::thread prod(producer);
    std::thread con(consumer);
    prod.join();
    con.join();

    return 0;
}
