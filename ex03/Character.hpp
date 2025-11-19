#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
  private:
    std::string name;
    AMateria *inventory[4];

  public:
    Character(void);
    Character(Character const &other);
    Character &operator=(Character const &other);
    ~Character(void);

    Character(std::string const &name);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

void deleteDroppedMaterias();
