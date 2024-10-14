#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

	srand(time(0));
	
	try {
		// Création de bureaucrates avec différents grades
		Bureaucrat alice("Alice", 25);   // Grade 25
		Bureaucrat bob("Bob", 72);       // Grade 72
		Bureaucrat charlie("Charlie", 150);  // Grade 150

		// Création de formulaires
		ShrubberyCreationForm shrubbery("garden");
		RobotomyRequestForm robotomy("robot_target");
		PresidentialPardonForm pardon("pardon_target");

		// Tentative de signature et d'exécution de chaque formulaire par des bureaucrates
		std::cout << "=== Tentative d'exécution sans signature ===\n";
		try {
			bob.executeForm(robotomy);  // Devrait échouer (non signé)
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n=== Signature et exécution du formulaire Shrubbery par Bob ===\n";
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);  // Devrait réussir

		std::cout << "\n=== Signature et tentative d'exécution du formulaire Robotomy par Charlie ===\n";
		try {
			charlie.signForm(robotomy);  // Grade insuffisant pour signer
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n=== Signature et exécution réussie du formulaire Robotomy par Alice ===\n";
		alice.signForm(robotomy);
		alice.executeForm(robotomy);  // Devrait réussir 50% du temps

		std::cout << "\n=== Signature et exécution du formulaire Presidential Pardon par Alice ===\n";
		alice.signForm(pardon);
		alice.executeForm(pardon);  // Devrait réussir

	} catch (const std::exception& e) {
		std::cerr << "Erreur: " << e.what() << std::endl;
	}

	return 0;
}
