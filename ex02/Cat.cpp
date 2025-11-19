#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

// Orthodox Canonical Form
Cat::Cat(void) : Animal("Cat"), brain(new Brain) {
    std::cout << "Cat constructor called\n";
}
Cat::Cat(Cat const &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat virtual destructor called\n";
    delete brain;
}

// Other methods
void Cat::makeSound() const { std::cout << "Cat meows silently!\n"; }
