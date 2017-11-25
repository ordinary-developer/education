#include <iostream>
#include <memory>
namespace example01 {

class Lifeform {
    public:
        virtual ~Lifeform() = default;

        virtual void eat() = 0;
        virtual void move() = 0;
};

class Flyable {
    public:
        virtual ~Flyable() = default;

        virtual void fly() = 0;
};

class Audible {
    public:
        virtual ~Audible() = default;

        virtual void makeSound() = 0;
};

class Sparrow : public Lifeform, public Flyable, public Audible {
    public:
        virtual ~Sparrow() override = default;

        virtual void eat() override { 
            std::cout << "[sparrow] -> eat() " << std::endl;
        }
        virtual void move() override {
            std::cout << "[sparrow] -> move() " << std::endl;
        }

        virtual void fly() override {
            std::cout << "[sparrow] -> fly() " << std::endl;
        }
        
        virtual void makeSound() override {
            std::cout << "[sparrow] -> makeSound() " << std::endl;
        }
};

class Pengwin : public Lifeform, public Audible {
    public:
        virtual ~Pengwin() override = default;

        virtual void eat() override {
            std::cout << "[pengwin] -> eat() " << std::endl;
        }

        virtual void move() override {
            std::cout << "[pengwin] -> move() " << std::endl;
        }

        virtual void makeSound() override {
            std::cout << "[pengwin] -> makeSound() " << std::endl;
        }

};

void run() {
    auto sparrow = std::make_unique<Sparrow>();
    sparrow->eat();
    sparrow->move();
    sparrow->fly();
    sparrow->makeSound();

    auto pengwin = std::make_unique<Pengwin>();
    pengwin->eat();
    pengwin->move();
    pengwin->makeSound();
}
}

int main() {
    example01::run();

    return 0;
}
