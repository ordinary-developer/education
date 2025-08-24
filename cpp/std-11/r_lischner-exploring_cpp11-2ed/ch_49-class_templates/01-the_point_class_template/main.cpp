#include <iostream>

template<class T>
class point {
    public:
        point(T x, T y) : x_{ x }, y_{ y } { }

        T x() const { return x_; }
        T y() const { return y_; }

        void move_to(T x, T y);
        void move_by(T x, T y);
    private:
        T x_, y_;
};

template<class T>
void point<T>::move_to(T x, T y) {
    x_ = x;
    y_ = y;
}

template<class T>
void point<T>::move_by(T x, T y) {
    x_ += x;
    y_ += y;
}


int main() {
    point<double> p{ 1, 1 };
    p.move_to(2, 2);
    p.move_by(3, 3);

    return 0;
}
