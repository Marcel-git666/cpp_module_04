#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {}

AMateria::AMateria(AMateria const &other) : type(other.type) {
#if DEBUG
    std::cout << "AMateria copy constructor called\n";
#endif
}

AMateria &AMateria::operator=(AMateria const &other) {
#if DEBUG
    std::cout << "AMateria copy assignment operator called\n";
#endif
    (void)other;
    return *this;
}

AMateria::~AMateria(void) {}

// Other methods
AMateria::AMateria(std::string const &type) : type(type) {
#if DEBUG
    std::cout << "AMateria constructor called with type: " << type << "\n";
#endif
}
std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter &target) { (void)target; }
