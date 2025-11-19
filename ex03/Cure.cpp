#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
#if DEBUG
    std::cout << "Cure constructor called\n";
#endif
}

Cure::Cure(Cure const &other) : AMateria(other) {
#if DEBUG
    std::cout << "Cure copy constructor called\n";
#endif
}

Cure &Cure::operator=(Cure const &other) {
#if DEBUG
    std::cout << "Cure copy assignment operator called\n";
#endif
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure(void) { std::cout << "Cure destructor called\n"; }

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "\'s wounds *" << '\n';
}
