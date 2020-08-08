#include <future>
#include <memory>
#include <iostream>

using FactorialPromise = std::promise<long long>;

long long Factorial(unsigned int value) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return (value == 1 ? 1 : value * Factorial(value - 1));
}

void ThreadTask(FactorialPromise&& threadPromise, unsigned int value) {
    threadPromise.set_value(Factorial(value));
}

int main() {
    FactorialPromise promise{};
    std::future<long long> taskFuture{ promise.get_future() };

    std::thread taskThread{ ThreadTask, std::move(promise), 3 };
    while (std::future_status::ready != 
            taskFuture.wait_until(std::chrono::system_clock::now() + 
                                  std::chrono::seconds(1)))
    {
        std::cout << "Stil Waiting!" << std::endl;
    }

    std::cout << "Factorial result was " << taskFuture.get() << std::endl;
    taskThread.join();

    return 0; 
}
