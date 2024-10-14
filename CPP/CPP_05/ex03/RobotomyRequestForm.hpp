#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>  // Pour rand()

class RobotomyRequestForm : public Form {
private:
	std::string target;

public:
	// Orthodox Canonical Form
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	// Méthode execute
	void execute(const Bureaucrat& executor) const;
};

#endif
