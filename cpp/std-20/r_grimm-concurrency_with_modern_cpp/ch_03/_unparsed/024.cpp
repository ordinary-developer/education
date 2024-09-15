#include <iostream>
#include <thread>


int main() {
    std::cout << std::boolalpha << std::endl;

    std::cout << "hardware_concurrency() = " << std::thread::hardware_concurrency() << std::endl;

    std::thread t1{ [] { std::cout << "t1 with id = " << std::this_thread::get_id() << std::endl; } };
    std::thread t2{ [] { std::cout << "t2 with id = " << std::this_thread::get_id() << std::endl; } };

    std::cout << std::endl;

    std::cout << "FROM MAIN: id of t1 " << t1.get_id() << std::endl;
    std::cout << "FROM MAIN: id of t2 " << t2.get_id() << std::endl;

    std::cout << std::endl;

    std::swap(t1, t2);
    std::cout << "FROM MAIN: id of t1 " << t1.get_id() << std::endl;
    std::cout << "FROM MAIN: id of t2 " << t2.get_id() << std::endl;

    std::cout << std::endl;

    std::cout << "FROM MAIN: id of main = " << std::this_thread::get_id() << std::endl;

    std::cout << std::endl;

    std::cout << "t1.joinable(): " << t1.joinable() << std::endl;
    std::cout << "t2.joinable(): " << t2.joinable() << std::endl;

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    std::cout << std::endl;
    
    std::cout << "t1.joinable(): " << t1.joinable() << std::endl;
    std::cout << "t2.joinable(): " << t2.joinable() << std::endl;

    std::cout << std::endl;
}
