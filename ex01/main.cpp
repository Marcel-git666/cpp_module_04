#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NC "\033[0m"

int main(void) {
    // --- 1. SUBJECT REQUIREMENT: ARRAY OF ANIMALS ---
    std::cout << GREEN << "\n--- 1. ARRAY OF ANIMALS TEST ---" << NC
              << std::endl;

    // Zadání chce pole objektů Animal
    const int arraySize = 4;
    const Animal *animals[arraySize];

    std::cout << BLUE << "Filling the array (Half Dogs, Half Cats)..." << NC
              << std::endl;
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Tady bys měl slyšet zvuky, pokud chceš, ale není to nutné
    // animals[0]->makeSound();

    std::cout << BLUE << "\nDeleting the array..." << NC << std::endl;
    // Tohle je kritický moment. Musí se zavolat:
    // ~Dog() -> ~Brain() -> ~Animal()
    // nebo ~Cat() -> ~Brain() -> ~Animal()
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    std::cout << GREEN << "--- Array Test Finished ---\n" << NC << std::endl;

    // --- 2. DEEP COPY TEST ---
    std::cout << GREEN << "\n--- 2. DEEP COPY TEST ---" << NC << std::endl;
    std::cout << YELLOW << "Creating 'basic' Dog..." << NC << std::endl;
    Dog basic;

    {
        std::cout
            << YELLOW
            << "\nCreating 'tmp' Dog as a copy of 'basic' (inside scope)..."
            << NC << std::endl;
        Dog tmp = basic;

        // Pokud bys měl Shallow Copy (mělkou kopii), 'tmp' i 'basic' by sdíleli
        // stejný Brain pointer. Až tenhle blok skončí, zavolá se destruktor
        // 'tmp' a smaže Brain.
    }
    std::cout << YELLOW << "\n'tmp' went out of scope and was destroyed." << NC
              << std::endl;

    std::cout << YELLOW << "Now accessing 'basic'..." << NC << std::endl;
    // Pokud máš Shallow Copy, 'basic' teď má smazaný mozek (Dangling Pointer).
    // Až funkce main skončí, 'basic' se pokusí smazat mozek znovu -> Double
    // Free Crash! Pokud máš Deep Copy, 'basic' má svůj vlastní mozek a nic se
    // nestane.

    std::cout
        << GREEN
        << "--- Deep Copy Test Finished (waiting for 'basic' destructor) ---\n"
        << NC << std::endl;

    return 0;
}
