#include <future>
#include <thread>
#include <iostream>
#include <vector>

std::promise<void> p;

void react() {
    std::cout << "reacting to an event" << std::endl;
}

void detect() {
    auto sf = p.get_future().share();

    std::vector<std::thread> vt;
    unsigned int threadsToRun = 3;
    for (unsigned int i = 0; i < threadsToRun; ++i) {
        vt.emplace_back([sf]() { sf.wait(); react(); });
    }

    p.set_value();

    for (auto& t: vt) 
        t.join();
}


int main() {
    detect();    
    return 0;
}
