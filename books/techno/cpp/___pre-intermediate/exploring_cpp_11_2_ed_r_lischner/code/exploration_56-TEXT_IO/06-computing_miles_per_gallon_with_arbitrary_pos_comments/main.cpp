#include <iostream>
#include <sstream>
#include <string>


int main() {
    double prev_odometer{ 0.0 };
    double total_fuel{ 0.0 };
    double total_distance{ 0.0 };

    std::string line{};
    int linenum{ 0 };
    bool error{ false };
    while (std::getline(std::cin, line)) {
        ++linenum;
        std::string::size_type comment{ line.find('#') };
        if (std::string::npos != comment) 
            line.erase(comment);

        std::istringstream input{ line };
        
        double odometer{};
        if (input >> odometer) {
            double fuel{};
            if (not (input >> fuel)) {
                std::cerr << "Missing fuel consumption on line "
                          << linenum << '\n';
                error = true;
            }
            else if (0 != fuel) {
                double distance{ odometer - prev_odometer };
                std::cout << distance / fuel << '\n';
                total_fuel += fuel;
                total_distance += distance;
                prev_odometer = odometer;
            }
        }
    }

    if (0 != total_fuel) {
        std::cout << "Net MPG = " << total_distance / total_fuel;
        if (error)
            std::cout << " (estimated, due to input error)";
        std::cout << '\n';
    }

    return 0;
}
