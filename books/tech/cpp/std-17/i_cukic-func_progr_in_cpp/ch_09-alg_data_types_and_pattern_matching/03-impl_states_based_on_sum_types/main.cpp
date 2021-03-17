#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <variant>
#include <cassert>
namespace workspace {

template <typename... Fs>
struct overloaded : Fs... { using Fs::operator()...; };

template <typename... Fs> overloaded(Fs...) -> overloaded<Fs...>;

class program_t {
private:
    class init_t {};

    class running_t {
    public:
        running_t(std::string const& filename) : m_file{filename} {}

        void count_words() {
            m_count = std::distance(
                std::istream_iterator<std::string>{m_file},
                std::istream_iterator<std::string>{});
        }

        unsigned count() const { return m_count; }

    private:
        unsigned m_count = 0;
        std::ifstream m_file;
    };

    class finished_t {
    public:
        finished_t(unsigned const count = 0) : m_count{count} {}

        unsigned count() const { return m_count; }

    private:
        unsigned m_count;
    };

    std::variant<init_t, running_t, finished_t> m_state;

public:
    program_t() : m_state{init_t{}} {}

    void count_words(std::string const& filename) {
        assert(0 == m_state.index());

        m_state = running_t{filename};
        std::get<running_t>(m_state).count_words();

        void counting_finished();
    }

    void counting_finished() {
        const auto* state = std::get_if<running_t>(&m_state);
        assert(nullptr != state);
        m_state = finished_t{state->count()};
    }

    unsigned count() const {
        return std::visit(
            overloaded {
                [](init_t) {
                    return (unsigned)0;
                },
                [](running_t const& state) {
                    return state.count();
                },
                [](finished_t const& state) {
                    return state.count();
                }
            },
            m_state);
    }
};


void run() {
    program_t program{};
    program.count_words("main.cpp");

    std::cout << program.count() << std::endl;
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;
    
    return 0;
}
