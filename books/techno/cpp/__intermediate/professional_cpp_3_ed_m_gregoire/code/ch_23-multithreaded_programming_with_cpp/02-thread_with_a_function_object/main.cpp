#include <iostream>
#include <thread>

class Counter {
    public:
        Counter(int id, int iterationCount)
            : id_{id}, iterationCount_{iterationCount} { }

        void operator()() const {
            for (int i{0}; i < iterationCount_; ++i) {
                std::cout << "Counter " << id_ << " has value ";
                std::cout << i << std::endl;
            }
        }

    private:
        int id_;
        int iterationCount_;
};

int main() {
    std::thread t1{ Counter{ 1, 20 } };

    Counter c(2, 12);
    std::thread t2(c);

    std::thread t3(Counter(3, 10));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

