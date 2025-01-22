#include <iostream>
#include <thread>
#include <future>

using namespace std::literals;


void function1(std::stop_token stopToken, const std::string & str) {
    std::this_thread::sleep_for(1s);
    if (stopToken.stop_requested())
        std::cout << "[ .... ] func1, " << str << ": Stop requested" << std::endl;
}

void function2(std::promise<void> p,
               std::stop_token stopToken, const std::string & str)
{
    std::this_thread::sleep_for(1s);
    std::stop_callback callback(stopToken, [&str]{
        std::cout << "[ .... ] func2, " << str << ": Stop requested" << std::endl;
    });
    p.set_value();
}


int main() {
    std::cout << "[  ok  ] starting the app" << std::endl;

    std::stop_source stopSource;

    std::stop_token stopToken = std::stop_token(stopSource.get_token());

    std::thread thr1 = std::thread(function1, stopToken, "std::thread");
    std::jthread jthr = std::jthread(function1, stopToken, "std::jthread");

    auto aFuture1 = std::async([stopToken] {
        std::this_thread::sleep_for(1s);
        if (stopToken.stop_requested())
            std::cout << "[ .... ] std::async: stop requested" << std::endl;
    });

    std::promise<void> aPromise;
    auto aFuture2 = aPromise.get_future();
    std::thread thr2(function2, std::move(aPromise), stopToken, "std::promise");

    stopSource.request_stop();
    if (stopToken.stop_requested())
        std::cout << "[ .... ] main: Stop requested" << std::endl;

    thr1.join();
    thr2.join();

    std::cout << std::endl;
}
