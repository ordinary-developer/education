#ifndef RANDOMINT_HPP_
#define RANDOMINT_HPP_

#include <algorithm>
#include <random>

class randomint {
    public:
        typedef std::default_random_engine::result_type result_type;

        randomint(result_type low, result_type high)
            : prng_{ std::random_device{}() },
              distribution_{ std::min(low, high), std::max(low, high)}
        { }

        result_type operator()() {
            return distribution_(prng_);
        }

    private:
        std::default_random_engine prng_;
        std::uniform_int_distribution<result_type> distribution_;
};

#endif

