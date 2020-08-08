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

std::string remove_ctrl_mutating_1(std::string s) {
    std::string result;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }

    return result;
}

std::string remove_ctrl_reserve_2(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}

std::string remove_ctrl_ref_args_3(const std::string& s) {
    std::string result;
    result.reserve(s.length());
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}

std::string remove_ctrl_ref_args_it_4(const std::string& s) {
    std::string result;
    result.reserve(s.length());
    for (auto it = s.begin(), end = s.end(); it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
    return result;
}

void remove_ctrl_ref_result_it_5(std::string& result,
                                 std::string const& s)
{
    result.clear();
    result.reserve(s.length());
    for (auto it = s.begin(), end = s.end(); it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
}

void remove_ctrl_cstrings_6(char* destp, 
                            char const* srcp, size_t size) 
{
    for (size_t i = 0; i < size; ++i) {
        if (srcp[i] >= 0x20)
            *destp++ = srcp[i];
    }
    *destp = 0;
}


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

#include <iostream>
int main() {
    auto s = get_random_string();
    
    std::cout << "f0 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_0(s);
                 })
              << std::endl;

    std::cout << "f1 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_mutating_1(s);
                 })
              << std::endl;

    std::cout << "f2 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_reserve_2(s);
                 })
              << std::endl;

    std::cout << "f3 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_ref_args_3(s);
                 })
              << std::endl;

    std::cout << "f4 (micros): " 
              << measure_time([&s]() -> void {
                   remove_ctrl_ref_args_it_4(s);
                 })
              << std::endl;

    std::string result{};
    std::cout << "f5 (micros): " 
              << measure_time([&s, &result]() -> void {
                   remove_ctrl_ref_result_it_5(result, s);
                 })
              << std::endl;

    char p[s.length()];
    std::cout << "f6 (micros): " 
              << measure_time([&s, &p]() -> void {
                   remove_ctrl_cstrings_6(p, s.c_str(), s.length());
                 })
              << std::endl;

    return 0;
}
