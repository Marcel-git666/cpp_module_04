#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
  protected:
    std::string type;

  public:
    // Orthodox Canonical Form
    WrongAnimal(void);
    WrongAnimal(WrongAnimal const &other);
    WrongAnimal &operator=(WrongAnimal const &other);
    ~WrongAnimal(void);

    // Other methods
    std::string const &getType() const;
    void makeSound() const;
};
#endif
