#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
    std::cout << "Cure constructor called\n";
}

Cure::Cure(Cure const &other) : AMateria(other) {
    std::cout << "Cure copy constructor called\n";
}

Cure &Cure::operator=(Cure const &other) {
    std::cout << "Cure copy asignment operator called\n";
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
