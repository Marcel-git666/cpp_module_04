#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
  protected:
    std::string type;
    explicit Animal(std::string type);

  public:
    // Orthodox Canonical Form
    Animal(void);
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal(void);

    // Other methods
    std::string const &getType() const;
    virtual void makeSound() const = 0;
};
#endif
