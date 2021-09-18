#include <iostream>
#include <any>
#include <string>
namespace example_01 { // the "how to do it" section

inline bool is_integer(std::any const & a) { return a.type() == typeid(int); }

void run() {
    {
        using namespace std::string_literals;

        std::any value{42}; 
        value = 42.0;
        value = "42"s;
    }

    {
        std::any value = 42.0;

        try {
            auto d = std::any_cast<double>(value);
            std::cout << d << '\n';
        }
        catch (std::bad_any_cast const & e) {
            std::cout << e.what() << '\n';
        }
    }

    {
        std::any value{42};
        std::cout << "is integer: " << is_integer(value) << std::endl;
    }

    {
        auto ltest = [](std::any const & a) {
            if (a.has_value()) {
                std::cout << "has value" << '\n';
            }
            else {
                std::cout << "no value" << '\n';
            }
        };

        std::any value;
        ltest(value);
        value = 42;
        ltest(value);

        std::any value2 = 42;
        ltest(value2);
        value2.reset();
        ltest(value);
    }
}

} // example 01


#include <iostream>
#include <iomanip>
#include <any>
#include <chrono>
#include <string>
#include <vector>
namespace example_02 { // the "how it works" section

void log(std::any const & value) {
    if (value.has_value()) {
        auto const & tv = value.type();
        if (tv == typeid(int)) {
            std::cout << std::any_cast<int>(value) << '\n';
        }
        else if (tv == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(value) << '\n';
        }
        else if (tv == typeid(std::chrono::time_point<std::chrono::system_clock>)) {
            auto t = std::any_cast<std::chrono::time_point<
                std::chrono::system_clock>>(value);
            auto now = std::chrono::system_clock::to_time_t(t);
            std::cout << std::put_time(std::localtime(&now), "%F %T") << '\n';
        }
        else {
            std::cout << "unexpected value type" << '\n';
        }
    }
    else {
        std::cout << "(empty)" << '\n';
    }
}

void run() {
    {
        using namespace std::string_literals;

        log(std::any{});
        log(42);
        log("42"s);
        log(42.0);
        log(std::chrono::system_clock::now());
    }

    {
        using namespace std::string_literals;
        
        std::vector<std::any> values;
        values.push_back(std::any{});
        values.push_back(42);
        values.push_back("42"s);
        values.push_back(42.0);
        values.push_back(std::chrono::system_clock::now());

        for (auto const v : values)
            log(v);
    }
}

}

#include <iostream>
int main() {
    std::cout << "example 01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example 02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;

    return 0;
}