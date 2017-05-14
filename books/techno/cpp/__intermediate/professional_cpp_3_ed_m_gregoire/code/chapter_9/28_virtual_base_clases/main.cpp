#include <iostream>
class Animal {
    public:
        virtual void eat() = 0;
        virtual void sleep() { std::cout << "zzzzz...." << std::endl; }
};

class Dog : public virtual Animal {
    public:
        virtual void bark() { std::cout << "Woof!" << std::endl; }
        virtual void eat() override { 
            std::cout << "The dog has eaten." << std::endl; 
        }
};

class Bird : public virtual Animal { 
    public:
        virtual void chirp() { std::cout << "Chir!" << std::endl; }
        virtual void eat() override {
            std::cout << "The bird has eaten." << std::endl;
        }
};

class DogBird : public Dog, public Bird {
    public:
        virtual void eat() override { Dog::eat(); }
};

auto main() -> int {
    DogBird myConfusedAnimal;
    myConfusedAnimal.sleep();
    return 0;
}
