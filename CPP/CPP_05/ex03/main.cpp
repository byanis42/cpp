#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		// Création de l'intern
		Intern someRandomIntern;

		// Bureaucrates
		Bureaucrat alice("Alice", 45);
		Bureaucrat bob("Bob", 140);

		// Demande de création de formulaires par l'Intern
		Form* shrubbery = someRandomIntern.makeForm("shrubbery creation", "garden");
		Form* robotomy = someRandomIntern.makeForm("robotomy request", "robot_target");
		Form* pardon = someRandomIntern.makeForm("presidential pardon", "pardon_target");
		Form* unknown = someRandomIntern.makeForm("unknown form", "unknown_target");  // Devrait échouer

		// Signature et exécution de formulaires
		if (shrubbery) {
			alice.signForm(*shrubbery);
			alice.executeForm(*shrubbery);
		}

		if (robotomy) {
			bob.signForm(*robotomy);
			bob.executeForm(*robotomy);
		}

		if (pardon) {
			alice.signForm(*pardon);
			alice.executeForm(*pardon);
		}

		// Nettoyage
		delete shrubbery;
		delete robotomy;
		delete pardon;
		delete unknown;  // Supp le null ptr au cas où

	} catch (const std::exception& e) {
		std::cerr << "Erreur: " << e.what() << std::endl;
	}

	return 0;
}
