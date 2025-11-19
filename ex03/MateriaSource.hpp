#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    AMateria *spellbook[4];

  public:
    // Orthodox Canonical Form
    MateriaSource(void);
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};
