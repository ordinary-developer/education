#include <iostream>


class Animal {
    public:
        virtual void eat() = 0;
};

class Dog : public Animal {
    public:
        virtual void bark() { std::cout << "Woof!" << std::endl; }
        virtual void eat() override 
            { std::cout << "The dog has eaten." << std::endl;}
};

class Bird : public Animal {
    public:
        virtual void chirp() { std::cout << "Chirp!" << std::endl; }
        virtual void eat() override 
            { std::cout << "The bird has eatern." << std::endl; }
};

class DogBird : public Dog, public Bird {
    public:
        using Dog::eat;
};

auto main() -> int {
    DogBird dogbird;
    dogbird.eat();

    return 0;
}
