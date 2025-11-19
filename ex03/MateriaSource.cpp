
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include <string>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        spellbook[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &other) {
#if DEBUG
    std::cout << "MateriaSource copy constructor called\n";
#endif
    for (int i = 0; i < 4; i++) {
        spellbook[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
        if (other.spellbook[i] != NULL) {
            spellbook[i] = other.spellbook[i]->clone();
        }
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
#if DEBUG
    std::cout << "MateriaSource copy asignment operator called\n";
#endif

    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (spellbook[i])
                delete spellbook[i];
        }
        for (int i = 0; i < 4; i++) {
            if (other.spellbook[i] != NULL) {
                spellbook[i] = other.spellbook[i]->clone();
            } else {
                spellbook[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (spellbook[i])
            delete spellbook[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++) {
        if (spellbook[i] == NULL) {
            spellbook[i] = m->clone();
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (spellbook[i] && spellbook[i]->getType() == type) {
            AMateria *newSpell = spellbook[i]->clone();
            return newSpell;
        }
    }
    return NULL;
}
