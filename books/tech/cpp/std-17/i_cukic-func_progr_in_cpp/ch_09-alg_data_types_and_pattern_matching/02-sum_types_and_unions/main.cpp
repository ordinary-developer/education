#include <variant>
#include <cassert>
namespace workspace {

class init_t {};

class running_t {
public:
    unsigned count() const { return m_count; }

private:
    unsigned m_count = 0;
};

class finished_t {
public:
    finished_t(unsigned const count) : m_count{count} {}

    unsigned count() const { return m_count; }

private:
    unsigned m_count;
};


class program_t {
public:
    program_t() : m_state{init_t{}} {}

    void start() {
        assert((nullptr != std::get_if<init_t>(&m_state)));

        m_state = running_t{};
    }

    void finish() {
        auto * state = std::get_if<running_t>(&m_state);
        assert(nullptr != state);

        m_state = finished_t{state->count()};
    }

private:
    std::variant<init_t, running_t, finished_t> m_state;
};

void run() {
    program_t program{};
    program.start();
    program.finish();
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
