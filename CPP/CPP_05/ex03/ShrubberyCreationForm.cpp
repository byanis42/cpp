#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Constructeur par défaut
ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("Shrubbery Creation", 145, 137), target("default_target") {}

// Constructeur avec paramètre
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("Shrubbery Creation", 145, 137), target(target) {}

// Constructeur de copie
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other), target(other.target) {}

// Opérateur d'affectation
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		Form::operator=(other); // Appelle l'opérateur d'affectation de la classe mère
		this->target = other.target;
	}
	return *this;
}

// Destructeur
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Méthode execute
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}

	// Création du fichier <target>_shrubbery
	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile) {
		std::cerr << "Error: couldn't create file" << std::endl;
		return;
	}

	// Arbre ASCII à écrire dans le fichier
	outfile << "       ###\n"
	        << "      #o###\n"
	        << "    #####o###\n"
	        << "   #o#\\#|#/###\n"
	        << "    ###\\|/#o#\n"
	        << "     # }|{  #\n"
	        << "       }|{\n";

	outfile.close();
	std::cout << "Shrubbery created in " << target << "_shrubbery" << std::endl;
}
