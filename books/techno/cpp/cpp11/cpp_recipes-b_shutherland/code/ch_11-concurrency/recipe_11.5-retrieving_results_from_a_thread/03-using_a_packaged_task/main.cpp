#include <future>
#include <iostream>

long long Factorial(unsigned int value) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return (value == 1 ? 1 : value * Factorial(value - 1));
}

int main() {
    std::packaged_task<long long(unsigned int)> task{ Factorial };
    std::future<long long> taskFuture{ task.get_future() };

    std::thread taskThread{ std::move(task), 3 };
    while (std::future_status::ready != 
            taskFuture.wait_until(std::chrono::system_clock::now() +
                                  std::chrono::seconds(1)))
    {
        std::cout << "Still Waiting!" << std::endl;
    }

    std::cout << "Factorial result was " << taskFuture.get() << std::endl;
    taskThread.join();

    return 0;
}
