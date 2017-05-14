#include <iostream>

class Dog {
    public:
        virtual void bark() { std::cout << "Woof!" << std::endl; }
};

class Bird {
    public:
        virtual void chirp() { std::cout << "Chirp!" << std::endl; }
};

class DogBird : public Dog, public Bird {
};


auto main() -> int {
    DogBird myConfusedAnimal;
    myConfusedAnimal.bark();
    myConfusedAnimal.chirp();

    return 0;
}
