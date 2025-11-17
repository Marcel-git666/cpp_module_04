#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

int main(void) {
    std::cout << GREEN << "\n--- 1. ABSTRACT CLASS TEST ---" << NC << std::endl;

    // -------------------------------------------------------
    // UNCOMMENT THE BLOCK BELOW TO TEST FOR COMPILATION ERROR:
    // -------------------------------------------------------
    /*
    std::cout << "Trying to create Animal..." << std::endl;
    Animal test;              // This must cause a compilation error!
    Animal* p = new Animal(); // This must also cause a compilation error!
    */
    // -------------------------------------------------------

    std::cout
        << "Success: Cannot instantiate Animal directly (check code to verify)."
        << std::endl;

    std::cout << GREEN << "\n--- 2. POLYMORPHISM TEST (Must still work) ---"
              << NC << std::endl;

    // Pointers to abstract classes are allowed!
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "Dog says: ";
    j->makeSound(); // Should output Dog sound
    std::cout << "Cat says: ";
    i->makeSound(); // Should output Cat sound

    delete j;
    delete i;

    std::cout << GREEN << "\n--- 3. DEEP COPY TEST (From Ex01) ---" << NC
              << std::endl;
    // Verifying that previous logic didn't break
    std::cout << "Creating 'basic' Dog..." << std::endl;
    Dog basic;
    {
        std::cout << "Creating 'tmp' copy of 'basic'..." << std::endl;
        Dog tmp = basic;
    } // tmp goes out of scope here
    std::cout << "Deep copy logic preserved (no double free crash)."
              << std::endl;

    return 0;
}
