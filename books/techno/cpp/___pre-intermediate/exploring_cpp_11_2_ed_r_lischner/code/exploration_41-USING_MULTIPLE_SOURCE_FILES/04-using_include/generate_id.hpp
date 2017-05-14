#pragma once

class generate_id {
    public:
        generate_id() : counter_{ 0 } { }
        long next();
    private:
        int unused_;
        short counter_;
        static short prefix_;
        static short const max_counter_ = 32767;
};
