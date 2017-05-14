class X { };
class Y { };

auto main() -> int {
    X x;
    Y y;
    X* xp = &x;
    Y* yp = &y;
    xp = reinterpret_cast<X*>(yp);

    void* p = xp;
    xp = reinterpret_cast<X*>(p);

    X& xr = x;
    Y& yr = reinterpret_cast<Y&>(x);
    
    return 0;
}
