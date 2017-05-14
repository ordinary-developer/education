#include <thread>

class ThreadRAII {
    public:
        enum class DtorAction { join, detach };

        ThreadRAII(std::thread&& t, DtorAction a)
            : action(a), t(std::move(t)) { }

        ~ThreadRAII() {
            if (t.joinable()) {
                if (DtorAction::join == action) {
                    t.join();
                }
                else {
                    t.detach();
                }
            }
        }

        ThreadRAII(ThreadRAII&&) = default;
        ThreadRAII& operator = (ThreadRAII&&) = default;

        std::thread& get() { return t; }

    private:
        DtorAction action;
        std::thread t;
};

int main() { 
    return 0;
}
