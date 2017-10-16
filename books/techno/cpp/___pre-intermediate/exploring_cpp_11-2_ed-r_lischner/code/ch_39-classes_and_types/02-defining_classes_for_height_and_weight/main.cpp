#include <iostream>

class height {
    public:
        explicit height(int h) : value_{ h } { }
        height(const height&) = default;
        ~height() = default;

        int value() const { return value_; }

    private:
        int value_;
};

class weight {
    public:
        explicit weight(int w) : value_{ w } { }
        weight(const weight&) = default;
        ~weight() = default;

        int value() const { return value_; }

    private:
        int value_;
};

class bmi {
    public:
        bmi() : value_{ 0 } { }
        bmi(height h, weight w)
            : value_{ w.value() * 10000 / (h.value() * h.value()) }
        { }
        bmi(const bmi&) = default;
        ~bmi() = default;

        int value() const { return value_; }

    private:
        int value_;
};

height operator+(height a, height b) {
    return height{ a.value() + b.value() };
}

int operator/(height a, height b) {
    return a.value() / b.value();
}

std::istream& operator>>(std::istream& in, height& h) {
    int tmp{};
    if (in >> tmp)
        h = height{ tmp };
    return in;
}

std::istream& operator>>(std::istream& in, weight& w) {
    int tmp{};
    if (in >> tmp)
        w = weight{ tmp };
    return in;
}

std::ostream& operator<<(std::ostream& out, bmi i) {
    out << i.value();
    return out;
}

int main() {
    std::cout << "Height in centimeters: ";
    height h{ 0 };
    std::cin >> h;

    std::cout << "Weight in kilograms: ";
    weight w{ 0 };
    std::cin >> w;

    std::cout << "Body-mass index = " << bmi(h, w);

    return 0;
}
