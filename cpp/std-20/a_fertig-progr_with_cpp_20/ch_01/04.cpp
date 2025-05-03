#include <iostream>
#include <mutex>
#include <cassert>
namespace example_01 {

std::mutex globalOsMutex;

void DoLocked(std::invocable auto&& f)
{
    std::lock_guard lock{globalOsMutex};
    f();
}


void run() {
    DoLocked([]{ assert(true); });

    std::cout << "[ ok ] example 01" << std::endl;
}

}



int main() {
    example_01::run();
}