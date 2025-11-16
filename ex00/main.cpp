#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// --- ANSI Color Codes ---
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define NC "\033[0m" // No Color

int main(void) {
    std::cout << GREEN << "\n--- 1. TESTING POLYMORPHISM (Correct Animals) ---"
              << NC << std::endl;

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "Pointer 'j' is type: " << j->getType() << std::endl;
    std::cout << "Pointer 'i' is type: " << i->getType() << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "Expecting Cat sound:" << NC << std::endl;
    std::cout << "Pointer 'i' (a Cat) says: ";
    i->makeSound();

    std::cout << YELLOW << "\nExpecting Dog sound:" << NC << std::endl;
    std::cout << "Pointer 'j' (a Dog) says: ";
    j->makeSound();

    std::cout << YELLOW << "\nExpecting Animal sound:" << NC << std::endl;
    std::cout << "Pointer 'meta' (an Animal) says: ";
    meta->makeSound();
    std::cout << std::endl;

    std::cout << "Deleting animals..." << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout << GREEN << "--- Polymorphism Test Finished ---\n"
              << NC << std::endl;

    std::cout << GREEN
              << "\n--- 2. TESTING LACK OF POLYMORPHISM (Wrong Animals) ---"
              << NC << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrong_i = new WrongCat();

    std::cout << "Pointer 'wrong_i' is type: " << wrong_i->getType()
              << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW
              << "Expecting WrongAnimal sound (due to no virtual):" << NC
              << std::endl;
    std::cout << "Pointer 'wrong_i' (a WrongCat) says: ";
    wrong_i->makeSound();

    std::cout << YELLOW << "\nExpecting WrongAnimal sound:" << NC << std::endl;
    std::cout << "Pointer 'wrongMeta' (a WrongAnimal) says: ";
    wrongMeta->makeSound();
    std::cout << std::endl;

    std::cout << "Deleting wrong animals..." << std::endl;
    delete wrongMeta;
    delete wrong_i;
    std::cout << GREEN << "--- Wrong Animal Test Finished ---\n"
              << NC << std::endl;

    std::cout << GREEN << "\n--- 3. TESTING COPY (OCF) ---" << NC << std::endl;

    std::cout << "Creating Original Dog..." << std::endl;
    Dog originalDog;
    std::cout << "Original Dog says: ";
    originalDog.makeSound();

    std::cout << "\nCreating Copy Dog..." << std::endl;
    Dog copyDog = originalDog;

    std::cout << YELLOW << "Expecting Dog sound (from copy):" << NC
              << std::endl;
    std::cout << "Copy Dog says: ";
    copyDog.makeSound();

    std::cout << YELLOW << "Expecting type 'Dog' (from copy):" << NC
              << std::endl;
    std::cout << "Copy Dog's type is: " << copyDog.getType() << std::endl;

    std::cout << "\nCreating Another Cat..." << std::endl;
    Cat catA;
    Cat catB;
    std::cout << YELLOW << "Expecting assignment operator call:" << NC
              << std::endl;
    catA = catB;

    std::cout << GREEN << "\n--- OCF Test Finished (scope will end) ---" << NC
              << std::endl;

    return 0;
}
