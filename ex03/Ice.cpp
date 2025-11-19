#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") { std::cout << "Ice constructor called\n"; }

Ice::Ice(Ice const &other) : AMateria(other) {
    std::cout << "Ice copy constructor called\n";
}

Ice &Ice::operator=(Ice const &other) {
    std::cout << "Ice copy asignment operator called\n";
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice(void) { std::cout << "Ice destructor called\n"; }

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n';
}
