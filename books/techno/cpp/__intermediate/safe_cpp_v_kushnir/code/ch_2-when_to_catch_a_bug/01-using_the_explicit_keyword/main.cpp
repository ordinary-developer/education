class Orange;
class Apple;
class Banana;

class Orange {
    public:
        explicit Orange(const Apple& apple, const Banana* p_banana = 0) { }
};

class Apple { 
    public:
        Orange AsOrange() const { return Orange(*this); }
};
class Banana { };

int main() {
    Apple apple{ };
    Orange orange1{ apple };
    Orange orange2{ apple.AsOrange() };

    return 0;
}

