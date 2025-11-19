#include "Brain.hpp"
#include <iostream>

// Orthodox Canonical Form
Brain::Brain(void) { std::cout << "Brain constructor called\n"; }
Brain::Brain(Brain const &other) {
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(Brain const &other) {
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(void) { std::cout << "Brain destructor called\n"; }
