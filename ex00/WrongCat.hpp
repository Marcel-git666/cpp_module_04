#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

  public:
    // Orthodox Canonical Form
    WrongCat(void);
    WrongCat(WrongCat const &other);
    WrongCat &operator=(WrongCat const &other);
    ~WrongCat(void);

    // Other methods

    void makeSound() const;
};
#endif
