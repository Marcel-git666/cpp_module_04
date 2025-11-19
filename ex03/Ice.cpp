#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
#if DEBUG
    std::cout << "Ice constructor called\n";
#endif
}

Ice::Ice(Ice const &other) : AMateria(other) {
#if DEBUG
    std::cout << "Ice copy constructor called\n";
#endif
}

Ice &Ice::operator=(Ice const &other) {
#if DEBUG
    std::cout << "Ice copy assignment operator called\n";
#endif
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice(void) {
#if DEBUG
    std::cout << "Ice destructor called\n";
#endif
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n';
}
