#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

  public:
    // Orthodox Canonical Form
    Dog(void);
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    virtual ~Dog(void);

    // Other methods

    virtual void makeSound() const;
};
#endif
