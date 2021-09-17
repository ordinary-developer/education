#include <chrono>
#include <iostream>
namespace example_01 { // the "how to do it" section

void run() {
    {
        std::chrono::hours half_day{12};
        std::chrono::minutes half_hour{30};
        std::chrono::seconds half_minute{30};
        std::chrono::milliseconds half_second{500};
        std::chrono::microseconds half_millisecond{500};
        std::chrono::nanoseconds half_microsecond{500};
    }
    
    {
        using namespace std::chrono_literals;
        
        auto half_day = 12h;
        auto half_hour = 30min;
        auto half_minute = 30s;
        auto half_second = 500ms;
        auto half_millisecond = 500us;
        auto half_microsecond = 500ns;
    }
    
    {
        std::chrono::hours half_day_in_h{12};
        std::chrono::minutes half_day_in_min{half_day_in_h};
        std::cout << half_day_in_h.count() << "h" << '\n';
        std::cout << half_day_in_min.count() << "min" << '\n';
    }
    
    {
        using namespace std::chrono_literals;
        
        auto total_seconds = 12345s;
        auto hours = 
            std::chrono::duration_cast<std::chrono::hours>(total_seconds);
        auto minutes =
            std::chrono::duration_cast<std::chrono::minutes>(total_seconds % 1h);
        auto seconds =
            std::chrono::duration_cast<std::chrono::seconds>(total_seconds % 1min);
            
        std::cout << hours.count() << ':' << minutes.count() << ':' << seconds.count() << '\n';
    }
    
    {
        using namespace std::chrono_literals;
        
        auto total_seconds = 12345s;
        auto m1 = std::chrono::floor<std::chrono::minutes>(total_seconds);
        auto m2 = std::chrono::round<std::chrono::minutes>(total_seconds);
        auto m3 = std::chrono::ceil<std::chrono::minutes>(total_seconds);
        auto sa = std::chrono::abs(total_seconds);
        
        std::cout << m1.count() << ":" << m2.count() << ":" << m3.count() << ":" << sa.count() << '\n';
    }
    
    {
        using namespace std::chrono_literals;
        
        auto d1 = 1h + 23min + 45s;
        auto d2 = 3h + 12min + 50s;
        if (d1 < d2) {
            std::cout << "d1 is less than d2" << std::endl;
        }
        else {
            std::cout << "d1 is not less than d2" << std::endl;
        }
    }
}
} // example_01


#include <chrono>
#include <iostream>
namespace example_02 { // the "how it works" section

void run() {
    std::chrono::duration<double, std::ratio<10>> d{1.2};
    std::cout << d.count() << std::endl;
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example 02 => [ok]" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    
    return 0;
}