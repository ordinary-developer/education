#include "generate_id.hpp"

short generate_id::prefix_{ 1 };

long generate_id::next() {
    if (counter_ == max_counter_)
        counter_ = 0;
    else
        ++counter_;
    return static_cast<long>(prefix_) * (max_counter_ + 1) + counter_;
}

