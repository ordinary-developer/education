#include <iostream>
#include <ostream>
#include <string>

class visible {
    public:
        visible(std::string&& msg) : msg_{std::move(msg) }
        { std::cout << msg_ << '\n'; }

        std::string const& msg() const { return msg_; }

    private:
        std::string msg_;
};

class base1 : public visible {
    public:
        base1(int x) : visible{"base1 constructed"}, value_{x} { }
        int value() const { return value_; }

    private:
        int value_;
};

class base2 : public visible {
    public:
        base2(std::string const& str) 
            : visible{"base{" + str +"} constructed"} { }
};

class base3 : public visible {
    public:
        base3() : visible{"base3 constructed"} { }
        int value() const { return 42; }
};

class derived : public base1, public base2, public base3 {
    public:
        derived(int i, std::string const& str) 
            : base1{i}, base2{str}, base3{} { }
        int value() const { return base1::value() + base3::value(); }
        std::string msg() const {
            return base1::msg() + "\n" + 
                   base2::msg() + "\n" +
                   base3::msg();
        }
};

int main() {
    derived d{ 42, "example" };
    std::cout << d.value() << '\n' << d.msg() << '\n';

    return 0;
}
