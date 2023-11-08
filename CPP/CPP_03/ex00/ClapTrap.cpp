#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " is here!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is gone!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage." << std::endl;
		if (hitPoints <= 0) {
			hitPoints = 0;
			std::cout << "ClapTrap " << name << " is out of hit points!" << std::endl;
		}
	} else {
		std::cout << "ClapTrap " << name << " is already out of hit points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0) {
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " points of health." << std::endl;
		if (hitPoints > 10) {
			hitPoints = 10;
		}
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " can't be repaired. Not enough energy points." << std::endl;
	}
}
