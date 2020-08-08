#include <iostream>

int main() {
    double total_fuel{ 0.0 };
    double total_distance{ 0.0 };
    double prev_odometer{ 0.0 };
    double fuel{}, odometer{};

    while (std::cin >> odometer >> fuel) {
        double distance{ odometer - prev_odometer };
        if (0 != distance) {
            std::cout << "fuel / distance = " << fuel / distance << '\n';
            total_fuel += fuel;
            total_distance += distance;
            prev_odometer = odometer;
        }
    }
    if (0 != total_distance)
        std::cout << "Net LPK = " << total_fuel / total_distance << '\n';

    return 0;
}
