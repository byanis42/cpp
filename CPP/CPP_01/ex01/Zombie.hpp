#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{

private:
    std::string _name;

public:
    Zombie();
	~Zombie();
	Zombie *newZombie (std::string name); // Ajout du constructeur avec un nom
    void    announce();
    void    putZombieName(std::string name);

};

Zombie*    zombieHorde(int N, std::string name);

#endif
