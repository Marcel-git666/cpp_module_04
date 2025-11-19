
#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

Character::Character() {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
    name = "Default character name";
}

Character::Character(Character const &other)
    : ICharacter(other), name(other.name) {
    std::cout << "Character copy constructor called\n";
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i] != NULL) {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

Character &Character::operator=(Character const &other) {
    std::cout << "Character copy asignment operator called\n";

    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i])
                delete inventory[i];
        }
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL) {
                inventory[i] = other.inventory[i]->clone();
            } else {
                inventory[i] = NULL;
            }
        }
    }
    return *this;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i])
            delete inventory[i];
    }
}

Character::Character(std::string const &name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

std::string const &Character::getName() const { return name; }

void Character::equip(AMateria *m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx <= 3) {
        if (inventory[idx] != NULL) {
            inventory[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter &target) {
    if (inventory[idx] != NULL && idx >= 0 && idx <= 3)
        inventory[idx]->use(target);
}
