#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
  protected:
    std::string type;
    Animal(void);
    Animal(Animal const &other);
    explicit Animal(std::string type);
    Animal &operator=(Animal const &other);

  public:
    virtual ~Animal(void);

    // Other methods
    std::string const &getType() const;
    virtual void makeSound() const = 0;
};
#endif
