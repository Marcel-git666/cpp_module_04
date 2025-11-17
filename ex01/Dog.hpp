#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

  private:
    Brain *brain;

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
