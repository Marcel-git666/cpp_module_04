#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

  private:
    Brain *brain;

  public:
    // Orthodox Canonical Form
    Cat(void);
    Cat(Cat const &other);
    Cat &operator=(Cat const &other);
    virtual ~Cat(void);

    // Other methods

    virtual void makeSound() const;
};
#endif
