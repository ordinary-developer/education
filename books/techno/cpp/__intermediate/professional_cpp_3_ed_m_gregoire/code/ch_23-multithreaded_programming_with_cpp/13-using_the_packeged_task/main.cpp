#include <future>
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::packaged_task<int(int, int)> task([](int number1, int number2) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        return number1 + number2;
    });
    auto future = task.get_future();

    task(2, 3);

    int result = future.get();
    std::cout << "the result is " << result << std::endl;

    return 0;
}
