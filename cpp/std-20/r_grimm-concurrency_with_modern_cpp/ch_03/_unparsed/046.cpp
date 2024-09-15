#include <iostream>
#include <future>
#include <utility>
#include <thread>

std::mutex coutMutex;

struct Div {
    void operator () (std::promise<int> && intPromise, int a, int b) {
        intPromise.set_value(a / b);
    }
};

struct Requestor {
    void operator () (std::shared_future<int> shaFut) {
        std::lock_guard<std::mutex> coutGuard(coutMutex);
        std::cout << "threadId(" << std::this_thread::get_id() << "): " ;
        std::cout << "20 / 10 = " << shaFut.get() << std::endl;
    }
};

int main() {
    std::cout << std::boolalpha << std::endl;

    std::promise<int> divPromise;

    std::future<int> divResult = divPromise.get_future();
    std::cout << "divResult.valid(): " << divResult.valid() << std::endl;

    Div div;
    std::thread divThread{ div, std::move(divPromise), 20, 10 };

    std::cout << "divResult.valid(): " << divResult.valid() << std::endl;
    
    std::shared_future<int> sharedResult = divResult.share();
    std::cout << "divResult.valid(): " << divResult.valid() << "\n\n";

    Requestor req;
    std::thread sharedThread1(req, sharedResult);
    std::thread sharedThread2(req, sharedResult);
    std::thread sharedThread3(req, sharedResult);
    std::thread sharedThread4(req, sharedResult);
    std::thread sharedThread5(req, sharedResult);

    divThread.join();

    sharedThread1.join();
    sharedThread2.join();
    sharedThread3.join();
    sharedThread4.join();
    sharedThread5.join();

    std::cout << std::endl;
}
