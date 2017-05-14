#include <future>
#include <thread>
#include <iostream>

std::promise<void> p;

void react() {
    std::cout << "reacting to an event" << std::endl;
}

void detect() {
    std::thread t([]()
                  { 
                      p.get_future().wait();
                      react();
                  });
    p.set_value();
    t.join();
}


int main() {
    detect();    
    return 0;
}
