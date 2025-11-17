#include "WrongAnimal.hpp"
#include <iostream>

// Orthodox Canonical Form
WrongAnimal::WrongAnimal(void) : type("DefaultWrongAnimal") {
    std::cout << "Default WrongAnimal constructor called\n";
}
WrongAnimal::WrongAnimal(WrongAnimal const &other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << "WrongAnimal copy asignment operator called\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called\n";
}

// Other methods
std::string const &WrongAnimal::getType() const { return type; }
void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes quiet noise.\n";
}
