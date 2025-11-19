#include "WrongCat.hpp"
#include <iostream>

// Orthodox Canonical Form
WrongCat::WrongCat(void) : WrongAnimal() {
    type = "Cat";
    std::cout << "WrongCat constructor called\n";
}
WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
    std::cout << "WrongCat copy assignment operator called\n";
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat destructor called\n"; }

// Other methods
void WrongCat::makeSound() const { std::cout << "WrongCat meows silently!\n"; }
