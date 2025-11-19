#include "AMateria.hpp"

class Cure : public AMateria {
  public:
    Cure(void);
    Cure(Cure const &other);
    Cure &operator=(Cure const &other);
    ~Cure(void);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};
