#include "RobotomyRequestForm.hpp"
#include <iostream>

// Constructeur par défaut
RobotomyRequestForm::RobotomyRequestForm()
	: Form("Robotomy Request", 72, 45), target("default_target") {}

// Constructeur avec paramètre
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("Robotomy Request", 72, 45), target(target) {}

// Constructeur de copie
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other), target(other.target) {}

// Opérateur d'affectation
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		Form::operator=(other);  // Appel à l'opérateur d'affectation de la classe mère
		this->target = other.target;
	}
	return *this;
}

// Destructeur
RobotomyRequestForm::~RobotomyRequestForm() {}

// Méthode execute
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException("Executor's grade is too low to execute the robotomy request.");
	}

	std::cout << "* drilling noises *" << std::endl;
	// 50% de chance de succès
	if (rand() % 2 == 0) {
		std::cout << target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomy failed on " << target << "." << std::endl;
	}
}
