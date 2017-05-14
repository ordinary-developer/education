#include <iostream>
#include <iomanip>
#include <locale>

int main() {
    bool myBool = true;
    std::cout << "This is the default: " << myBool << std::endl;
    std::cout << "This should be true: " << std::boolalpha << myBool << std::endl;
    std::cout << "This should be 1: " << std::noboolalpha << myBool << std::endl;

    int i = 123;
    printf("This should be '   123': %6d\n", i);
    std::cout << "This should be '   123': " << std::setw(6) << i << std::endl;

    printf("This should be '000123': %06d\n", i);
    std::cout << "This should be '000123': " << std::setfill('0') << std::setw(6)
              << i << std::endl;

    std::cout << "This should be '***123': " << std::setfill('*') << std::setw(6)
              << i << std::endl;
    std::cout << std::setfill(' ');

    std::cout.precision(5);
    std::cout << "This should be '1.2346': " << 1.23456789 << std::endl;

    double dbl = 1.452;
    double dbl2 = 5;
    std::cout << "This should be ' 5': " << std::setw(2) << std::noshowpoint
              << dbl2 << std::endl;
    std::cout << "this should be @@1.452: " << std::setw(7) << std::setfill('@')
              << dbl << std::endl;
    std::cout << std::setfill(' ');


    std::cout.imbue(std::locale(""));

    std::cout << "This is 1234567 formatted according to your location: " 
              << 1234567 << std::endl;

    std::cout << "This should be a money amount of 120000, "
              << "formatted according to your location: "
              << std::put_money("12000") << std::endl;

    time_t t_t = time(nullptr);
    tm* t = localtime(&t_t);
    std::cout << "This should be the current date and time "
              << "formatted according to your location: " << std::endl;
//              << std::put_time(t, "%c") << std::endl;
    std::cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
              << std::quoted("Quoted string with \"embedded quotes\".") << std::endl;

    return 0;
}
