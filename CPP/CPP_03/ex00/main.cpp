#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1("CL4P-TP");
	ClapTrap claptrap2("FR4G-TP");

	claptrap1.attack("Bandit");
	claptrap2.takeDamage(9999);
	claptrap1.beRepaired(2);

	return 0;
}
