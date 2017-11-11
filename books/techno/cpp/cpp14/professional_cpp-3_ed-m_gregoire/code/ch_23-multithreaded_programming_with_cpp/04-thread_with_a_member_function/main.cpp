#include <thread>
#include <iostream>

class Request {
    public:
        Request(int id) : id_{id} { }
        
        void process() 
        { std::cout << "Processing request " << id_ << std::endl; }

    private:
        int id_;
};

int main() {
    Request request{100};
    std::thread t{ &Request::process, &request };
    t.join();

    std::thread auxThread{ &Request::process, Request{200} };
    auxThread.join();

    return 0;
}
