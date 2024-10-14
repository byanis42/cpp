#include "Intern.hpp"
#include <iostream>

// Fonctions pour créer chaque type de formulaire
Form* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

Form* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

Form* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Constructeur par défaut
Intern::Intern() {}

// Constructeur de copie
Intern::Intern(const Intern& other) {
	(void)other;  // Rien à copier, l'Intern n'a pas de données membres
}

// Opérateur d'affectation
Intern& Intern::operator=(const Intern& other) {
	(void)other;  // Rien à assigner, l'Intern n'a pas de données membres
	return *this;
}

// Destructeur
Intern::~Intern() {}

// Méthode makeForm : crée un formulaire selon son nom
Form* Intern::makeForm(const std::string& formName, const std::string& target) {
	// Tableau de noms de formulaires et pointeurs de fonctions correspondants
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (*formCreators[])(const std::string&) = {
		&createShrubberyCreationForm,
		&createRobotomyRequestForm,
		&createPresidentialPardonForm
	};

	// Comparaison du nom du formulaire avec ceux supportés
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return formCreators[i](target);
		}
	}

	// Si aucun formulaire n'a été trouvé, message d'erreur
	std::cerr << "Intern could not create " << formName << " because it is an unknown form type." << std::endl;
	return NULL;
}
