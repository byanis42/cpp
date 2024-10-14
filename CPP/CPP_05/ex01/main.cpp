#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		// Création de bureaucrates
		Bureaucrat alice("Alice", 3);
		Bureaucrat bob("Bob", 50);

		// Création de formulaires
		Form formA("FormA", 5, 10);
		Form formB("FormB", 40, 30);

		// Affichage des formulaires
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		// Tentative de signatures
		alice.signForm(formA); // Alice peut signer
		bob.signForm(formA);   // Bob ne peut pas signer
		bob.signForm(formB);   // Bob peut signer

		// Affichage des résultats après signature
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Erreur: " << e.what() << std::endl;
	}

	return 0;
}
