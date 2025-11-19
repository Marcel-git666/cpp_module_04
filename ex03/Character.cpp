
#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

static AMateria *dropped_materias[1000];
static int dropped_count = 0;

Character::Character() {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
    name = "Default character name";
}

Character::Character(Character const &other)
    : ICharacter(other), name(other.name) {
#if DEBUG
    std::cout << "Character copy constructor called\n";
#endif
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
#if DEBUG
    std::cout << "Character copy asignment operator called\n";
#endif
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
    if (idx >= 0 && idx <= 3 && inventory[idx] != NULL) {
        if (dropped_count < 1000) { // Kontrola, zda nepřetéká koš
            dropped_materias[dropped_count] = inventory[idx];
            dropped_count++;
        }
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (inventory[idx] != NULL && idx >= 0 && idx <= 3)
        inventory[idx]->use(target);
}

void deleteDroppedMaterias() {
    for (int i = 0; i < dropped_count; i++) {
        if (dropped_materias[i] != NULL) {
            delete dropped_materias[i];
            dropped_materias[i] = NULL;
        }
    }
    dropped_count = 0;
}
