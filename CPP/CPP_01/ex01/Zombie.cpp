#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
}

void Zombie::announce() {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::putZombieName(std::string name) {
    this->_name = name;
}
