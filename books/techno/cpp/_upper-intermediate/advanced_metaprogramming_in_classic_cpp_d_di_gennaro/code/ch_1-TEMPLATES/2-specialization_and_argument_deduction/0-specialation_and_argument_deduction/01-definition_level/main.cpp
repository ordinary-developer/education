class X {                           // X - namespace level
    public:
        typedef double value_type;  // value_type - class level

        X(const X& y) { }           // X, y - class level

        void f() {                  // f - class level
            int z = 0;              // z - body level
            struct LOCAL { };       // LOCAL - local class
        }
};


int main() {
    return 0;
}
