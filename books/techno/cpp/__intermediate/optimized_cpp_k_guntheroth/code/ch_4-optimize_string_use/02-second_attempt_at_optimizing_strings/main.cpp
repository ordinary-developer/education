#include <chrono>
#include <functional>

double measure_time(std::function<void (void)> func_to_measure) {
    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    for (unsigned int i{ 0 }; i < 100; ++i)
        func_to_measure();

    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>
            (end - begin).count();

    return (double)duration / 100.0f;
}


#include <string>
#include <cstddef>

std::string remove_ctrl_0(std::string s) {
    std::string result;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result = result + s[i];
    }
    return result;
}

std::string remove_ctrl_block_1(std::string s) {
    std::string result;
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20)
                break;
        }
        result = result + s.substr(b, i - b);
    }
    return result;
}

std::string remove_ctrl_block_append_2(std::string s) {
    std::string result{};
    result.reserve(s.length());
    for (size_t b = 0, i = b; b < s.length(); b = i + 1) {
        for (i = b; i < s.length(); ++i) 
            if (s[i] < 0x20)
                break;
        result.append(s, b, i - b);
    }
    return result;
}



#include <iostream>
#include <random>
std::string get_random_string() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, 120);

    std::string result{};
    for (unsigned int i{ 0 }; i < 2000; ++i) {
        char c = uni(rng);
        result += c;
    }

    return result;
}

std::string remove_ctrl_erase_3(std::string s) {
    for (size_t i = 0; i < s.length(); ) 
        if (s[i] < 0x20)
            s.erase(i, 1);
        else
            ++i;

    return s;
}

int main() {
    auto s = get_random_string();
    
    std::cout << "f0 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_0(s);
                 })
              << std::endl;

    std::cout << "f1 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_block_1(s);
                 })
              << std::endl;

    std::cout << "f2 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_block_append_2(s);
                 })
              << std::endl;

    std::cout << "f3 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_erase_3(s);
                 })
              << std::endl;

    return 0;
}
