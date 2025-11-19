#include "Dog.hpp"
#include <iostream>

// Orthodox Canonical Form
Dog::Dog(void) : Animal() {
    type = "Dog";
    std::cout << "Dog constructor called\n";
}
Dog::Dog(Dog const &other) : Animal(other) {
    std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog(void) { std::cout << "Dog virtual destructor called\n"; }

// Other methods
void Dog::makeSound() const { std::cout << "Dog barks like mad!\n"; }
