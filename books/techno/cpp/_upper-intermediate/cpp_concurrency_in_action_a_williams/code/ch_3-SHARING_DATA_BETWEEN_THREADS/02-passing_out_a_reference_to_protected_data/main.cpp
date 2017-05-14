#include <mutex>
#include <string>

class some_data {
    public:
        void do_something() { }
    private:
        int a;
        std::string b;
};

class data_wrapper {
    public:
        template <typename Function>
        void process_data(Function func) {
            std::lock_guard<std::mutex> l(m);
            func(data);
        }
    private:
        some_data data;
        std::mutex m;

};

some_data* unprotected;

void malicious_function(some_data& protected_data) {
    unprotected = &protected_data;
}

data_wrapper x;

void foo() {
    x.process_data(malicious_function);
    unprotected->do_something();
}

int main() {
    foo();

    return 0;
}
