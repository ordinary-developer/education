#include <thread>
#include <iostream>


class ExempliGratia {
    public:
        ExempliGratia() 
            : master_thread(std::this_thread::get_id()) { }

        void operator() () {
            if (std::this_thread::get_id() == master_thread) {
                do_master_thread_work();
            }
            do_common_work();
        }

    private:
        void do_master_thread_work() {
            std::cout << "[master]: ..." << std::endl;
        }

        void do_common_work() {
            std::cout << "[" << std::this_thread::get_id() << "]..."
                      << std::endl;
        }

        std::thread::id master_thread;
};


int main() {
    ExempliGratia eg;

    std::thread t1(eg);
    std::thread t2(eg);
    std::thread t3(eg);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
