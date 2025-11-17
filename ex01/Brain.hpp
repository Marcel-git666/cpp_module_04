#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

  public:
    // Orthodox Canonical Form
    Brain(void);
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);
    ~Brain(void);

    // Properties
    std::string ideas[100];
};
#endif
