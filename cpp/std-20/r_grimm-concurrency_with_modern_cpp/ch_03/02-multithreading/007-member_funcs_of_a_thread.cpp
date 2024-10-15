#include <iostream>
#include <thread>


int main() {
    std::cout << std::boolalpha << '\n';

    std::cout << "hardware_concurrency() = " << std::thread::hardware_concurrency() << '\n';

    std::thread t1([]{ std::cout << "t1 with id = " << std::this_thread::get_id() << '\n'; });
    std::thread t2([]{ std::cout << "t2 with id = " << std::this_thread::get_id() << '\n'; });

    std::cout << '\n';

    std::cout << "FROM MAIN: id of t1 " << t1.get_id() << '\n';
    std::cout << "FROM MAIN: id of t2 " << t2.get_id() << '\n';

    std::cout << '\n';

    swap(t1, t2);

    std::cout << "FROM MAIN: id of t1 " << t1.get_id() << '\n';
    std::cout << "FROM MAIN: id of t2 " << t2.get_id() << '\n';

    std::cout << '\n';

    std::cout << "FROM MAIN: id of main = " << std::this_thread::get_id() << '\n';

    std::cout << '\n';

    std::cout << "t1.joinable(): " << t1.joinable() << '\n';

    std::cout << '\n';

    t1.join();
    t2.join();

    std::cout << '\n';

    std::cout << "t1.joinable(): " << t1.joinable() << '\n';

    std::cout << '\n';
}
