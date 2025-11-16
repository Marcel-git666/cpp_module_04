#include "Cat.hpp"
#include <iostream>

// Orthodox Canonical Form
Cat::Cat(void) : Animal() {
    type = "Cat";
    std::cout << "Cat constructor called\n";
}
Cat::Cat(Cat const &other) : Animal(other) {
    std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << "Cat copy asignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat(void) { std::cout << "Cat virtual destructor called\n"; }

// Other methods
void Cat::makeSound() const { std::cout << "Cat meows silently!\n"; }
