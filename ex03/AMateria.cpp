#include "AMateria.hpp"

AMateria::AMateria(void) : type("") {}

AMateria::AMateria(AMateria const &other) : type(other.type) {}

AMateria &AMateria::operator=(AMateria const &other) {
    (void)other;
    return *this;
}

AMateria::~AMateria(void) {}

// Other methods
AMateria::AMateria(std::string const &type) : type(type) {
    std::cout << "AMateria constructor called with type: " << type << "\n";
}
std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter &target) { (void)target; }
