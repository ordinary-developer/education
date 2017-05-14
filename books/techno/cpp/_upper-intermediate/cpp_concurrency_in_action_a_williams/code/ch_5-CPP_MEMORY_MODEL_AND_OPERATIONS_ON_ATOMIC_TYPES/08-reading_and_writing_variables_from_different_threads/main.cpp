#include <vector>
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

std::vector<int> data;
std::atomic_bool data_ready(false);

int main() {
    auto write_data = [&data, &data_ready]() {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        data.push_back(42);
        data_ready = true;
    };
    auto read_data = [&data, &data_ready]() {
        while (!data_ready.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        std::cout << "The answer is " << data[0] << std::endl;
    };

    std::thread writer(write_data);
    std::thread reader(read_data);
    writer.join();
    reader.join();

    return 0;
}
