#include <memory>
#include <cassert>
namespace workspace {

class state_t {
    protected:
        state_t(int type)
            : type{type} {}

    public:
        virtual ~state_t() {};
        int type;
};


class init_t : public state_t {
    public:
        enum { id = 0 };
        init_t() : state_t{id} {}
};


class running_t : public state_t {
    public:
        enum { id = 1 };
        running_t() : state_t{id} {}

        unsigned count() const { return m_count; }

    private:
        unsigned m_count = 0;
};


class finished_t : public state_t {
    public:
        enum { id = 2 };
        finished_t(unsigned count) : state_t{id}, m_count{count} {}

        unsigned count() const { return m_count; }

    private:
        unsigned m_count;
};


class program_t {
    public:
        program_t() : m_state{ std::make_unique<init_t>() } {}

        void start() {
            assert((init_t::id == m_state->type));
            m_state = std::make_unique<running_t>();
        }

        void finish() {
            assert((running_t::id == m_state->type));
            auto state = static_cast<running_t*>(m_state.get());
            m_state = std::make_unique<finished_t>(state->count());
        }

    private:
        std::unique_ptr<state_t> m_state;
};


void run() {
    program_t program{};
    program.start();
    program.finish();
}

} // workspace


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
