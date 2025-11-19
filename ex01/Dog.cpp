#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

// Orthodox Canonical Form
Dog::Dog(void) : Animal("Dog"), brain(new Brain) {
    std::cout << "Dog constructor called\n";
}

Dog::Dog(Dog const &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog virtual destructor called\n";
    delete brain;
}

// Other methods
void Dog::makeSound() const { std::cout << "Dog barks like mad!\n"; }
