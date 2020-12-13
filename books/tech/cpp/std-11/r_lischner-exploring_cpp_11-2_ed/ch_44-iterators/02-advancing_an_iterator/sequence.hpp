#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

class sequence {
    public:
        sequence(int start, int step) : value_{ start }, step_{ step } 
        { }
        sequence(int start) : sequence{ start, 1 } { }
        sequence() : sequence{ 0 } { }

        int operator()() {
            int result{ value_ };
            value_ += step_;
            return result;
        }
    private:
        int value_;
        int const step_;
};

#endif
