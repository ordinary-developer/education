#include <atomic>
#include <iostream>
#include <thread>
#include <cassert>
namespace example_01 { // more comlex example for std::relaxed_ordering

struct read_vals_struct { 
    int x, y, z;
};

std::atomic<int> x{0}, y{0}, z{0};
std::atomic<bool> go{false};
unsigned const loop_count{10};

read_vals_struct vals1[loop_count];
read_vals_struct vals2[loop_count];
read_vals_struct vals3[loop_count];
read_vals_struct vals4[loop_count];
read_vals_struct vals5[loop_count];

void increment(std::atomic<int>* var_to_inc, read_vals_struct* vals) {
    while (not go)
        std::this_thread::yield();
    for (unsigned i{0}; i < loop_count; ++i) {
        vals[i].x = x.load(std::memory_order_relaxed);
        vals[i].y = y.load(std::memory_order_relaxed);
        vals[i].z = z.load(std::memory_order_relaxed);
        var_to_inc->store(i + 1, std::memory_order_relaxed);
        std::this_thread::yield();
    }
}

void read_vals(read_vals_struct* vals) {
    while (not go)
        std::this_thread::yield();
    for (unsigned i{0}; i < loop_count; ++i) {
        vals[i].x = x.load(std::memory_order_relaxed);
        vals[i].y = y.load(std::memory_order_relaxed);
        vals[i].z = z.load(std::memory_order_relaxed);
        std::this_thread::yield();
    }
}

void print(read_vals_struct* vals) {
    for (unsigned i{0}; i < loop_count; ++i) {
        if (i)
            std::cout << ",";
        std::cout << "(" << vals[i].x << "," << vals[i].y << "," << vals[i].z << ")";
    }
    std::cout << std::endl;
}

void run() {
    std::thread t1{ increment, &x, vals1 };
    std::thread t2{ increment, &y, vals2 };
    std::thread t3{ increment, &z, vals3 };
    std::thread t4{ read_vals, vals4 };
    std::thread t5{ read_vals, vals5 };

    go = true;

    t5.join();
    t4.join();
    t3.join();
    t2.join();
    t1.join();

    std::cout << std::endl;
    print(vals1);
    print(vals2);
    print(vals3);
    print(vals4);
    print(vals5);
}

} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => [OK]"; example_01::run(); std::cout << std::endl << std::endl;

    return 0;
}
