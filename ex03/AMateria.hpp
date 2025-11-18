#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
  protected:
    std::string type;
    AMateria(void);
    AMateria(AMateria const &other);
    AMateria &operator=(AMateria const &other);

  public:
    virtual ~AMateria(void);

    // Other methods
    AMateria(std::string const &type);
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};
#endif
