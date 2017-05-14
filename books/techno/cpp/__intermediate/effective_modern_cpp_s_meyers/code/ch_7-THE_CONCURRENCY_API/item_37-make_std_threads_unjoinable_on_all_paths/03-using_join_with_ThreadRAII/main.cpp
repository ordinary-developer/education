#include <functional>
#include <vector>
#include <thread>
#include <random>
#include <future>

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

        ThreadRAII(ThreadRAII&) = default;
        ThreadRAII& operator = (ThreadRAII&&) = default;

        std::thread& get() { return t; }

    private:
        DtorAction action;
        std::thread t;
};

using namespace std::literals;

// a dumb function
bool conditionsAreSatisfied() {
    double lower_bound = 0;
    double upper_bound = 1000;
    std::uniform_real_distribution<double> unif(lower_bound,
                                                upper_bound);
    std::default_random_engine re;
    double value = unif(re);

    return value > 500;
}

// a dump function
bool performComputation(const std::vector<int>& values) {
    std::this_thread::sleep_for(5s);
}

constexpr auto tenMillion = 10'000'000;

bool doWork(std::function<bool(int)> filter,
            int maxVal = tenMillion)
{
    std::vector<int> goodVals;
    for (unsigned int i = 0; i < tenMillion; ++i) {
        goodVals.push_back((0 == i % 2) ? i + tenMillion
                                        : tenMillion - i);
    }

    ThreadRAII t(std::thread([&filter, maxVal, &goodVals]() 
                            {
                              for (auto i = 0; i <= maxVal; ++i) {
                                if (filter(i))
                                  goodVals.push_back(i);
                              }
                            }),
                 ThreadRAII::DtorAction::join);

    auto nh = t.get().native_handle();
    
    if (conditionsAreSatisfied()) {
        t.get().join();
        performComputation(goodVals); 
        return true;
    }

    return false;
}


int main() {
    std::function<bool(int)> filter = [](int i) { return true; };
    std::async(std::launch::async, 
               doWork,
               [](int i) { return true; },
               tenMillion);

    return 0;
}
