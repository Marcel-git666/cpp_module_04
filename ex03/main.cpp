#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << "\n--- 1. MATERIA SOURCE SETUP ---\n" << std::endl;

    IMateriaSource *src = new MateriaSource();
    AMateria *ice_template = new Ice();
    AMateria *cure_template = new Cure();

    src->learnMateria(ice_template);
    src->learnMateria(cure_template);

    delete ice_template;
    delete cure_template;
    std::cout << std::endl;

    std::cout << "\n--- 2. CHARACTER CORE FUNCTIONALITY ---\n" << std::endl;

    ICharacter *me = new Character("Me");
    ICharacter *bob = new Character("Bob");
    AMateria *tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n--- ME USING MATERIA (SHOULD OUTPUT: ICE, CURE) ---"
              << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n--- 3. UNEQUIP AND DEEP COPY TEST ---\n" << std::endl;

    AMateria *leak_test = src->createMateria("ice");
    me->equip(leak_test);

    std::cout << "Unequipping slot 2 (address saved in global array)."
              << std::endl;
    me->unequip(2);

    std::cout << "\n--- 4. DEEP COPY CHECK (Assignment) ---\n" << std::endl;
    Character *clone_me = new Character("CloneMe");

    *clone_me = *dynamic_cast<Character *>(me);

    std::cout << "\n--- 5. FINAL CLEANUP (Destructors) ---\n" << std::endl;

    delete clone_me;
    delete bob;
    delete me;
    delete src;
    deleteDroppedMaterias();
    return 0;
}
