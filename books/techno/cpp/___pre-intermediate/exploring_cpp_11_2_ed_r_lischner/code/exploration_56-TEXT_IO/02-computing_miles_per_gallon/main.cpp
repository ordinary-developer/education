#include <iostream>

int main() {
    double total_fuel{ 0.0 };
    double total_distance{ 0.0 };
    double prev_odomiter{ 0.0 };
    double fuel{}, odomiter{};

    while (std::cin >> odomiter >> fuel) {
        if (0 != fuel) {
            double distance{ odomiter - prev_odomiter };
            std::cout << "distance / fuel = " << distance / fuel << '\n';
            total_fuel += fuel;
            total_distance += distance;
            prev_odomiter = odomiter;
        }
    }
    if (0 != total_fuel) 
        std::cout << "Net MPG = " << total_distance / total_fuel << '\n';

    return 0;
}
