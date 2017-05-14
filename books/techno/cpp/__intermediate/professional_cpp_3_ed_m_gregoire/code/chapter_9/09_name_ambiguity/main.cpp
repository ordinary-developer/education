#include <iostream>

class Dog {
    public:
        virtual void bark() { std::cout << "Woof!" << std::endl; }
        virtual void eat() { std::cout << "The dog has eatern." << std::endl; }
};

class Bird {
    public:
        virtual void chirp() { std::cout << "Chirp!" << std::endl; }
        virtual void eat() { std::cout << "The birtd has eaten." << std::endl; }
};

class DogBird : public Dog, public Bird {
};


auto main() -> int {
    DogBird myConfusedAnimal;
    dynamic_cast<Dog&>(myConfusedAnimal).eat();
    myConfusedAnimal.Dog::eat();

    return 0;
}
