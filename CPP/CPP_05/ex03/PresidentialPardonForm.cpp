#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructeur par défaut
PresidentialPardonForm::PresidentialPardonForm()
	: Form("Presidential Pardon", 25, 5), target("default_target") {}

// Constructeur avec paramètre
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("Presidential Pardon", 25, 5), target(target) {}

// Constructeur de copie
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form(other), target(other.target) {}

// Opérateur d'affectation
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		Form::operator=(other);
		this->target = other.target;
	}
	return *this;
}

// Destructeur
PresidentialPardonForm::~PresidentialPardonForm() {}

// Méthode execute
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException("Executor's grade is too low to execute the presidential pardon.");
	}

	std::cout << target << " has been pardoned by the president." << std::endl;
}
