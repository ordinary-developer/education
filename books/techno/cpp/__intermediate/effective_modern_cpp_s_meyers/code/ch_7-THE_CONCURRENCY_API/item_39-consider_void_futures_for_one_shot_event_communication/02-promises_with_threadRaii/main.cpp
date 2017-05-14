#include <future>
#include <thread>
#include <iostream>

class ThreadRAII {
    public:
        enum class DtorAction { join, detach };

        ThreadRAII(std::thread t, DtorAction a)
            :_action(a), _t(std::move(t)) { }

        ~ThreadRAII() {
            if (_t.joinable()) 
                if (DtorAction::join == _action)
                    _t.join();
                else
                    _t.detach();
        }

        std::thread& get() { return _t; }

    private:
        DtorAction _action;
        std::thread _t;
};
std::promise<void> p;

void react() {
    std::cout << "reacting to an event" << std::endl;
}

void detect() {
    ThreadRAII tr(std::thread([]() -> void
                  { 
                      p.get_future().wait();
                      react();
                  }),
                  ThreadRAII::DtorAction::join);
    p.set_value();
}


int main() {
    detect();    
    return 0;
}
