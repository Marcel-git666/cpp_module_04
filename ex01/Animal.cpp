#include "Animal.hpp"
#include <iostream>

// Orthodox Canonical Form
Animal::Animal(void) : type("DefaultAnimal") {
    std::cout << "Default Animal constructor called\n";
}

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal constructor called with type: " << type << "\n";
}

Animal::Animal(Animal const &other) : type(other.type) {
    std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(Animal const &other) {
    std::cout << "Animal copy assignment operator called\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal(void) { std::cout << "Animal virtual destructor called\n"; }

// Other methods
std::string const &Animal::getType() const { return type; }
void Animal::makeSound() const {
    std::cout << "Animal makes ear-splitting noise.\n";
}
