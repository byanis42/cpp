#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException("Grade too high for form: " + name);
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException("Grade too low for form: " + name);
	}
}

// Copy constructor
Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Assignment operator
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
		// Les autres attributs sont constants et ne peuvent pas être modifiés
	}
	return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

// Methods
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign) {
		throw GradeTooLowException("Bureaucrat's grade is too low to sign the form: " + name);
	}
	isSigned = true;
}

// Méthode publique pour imprimer les détails du formulaire
void Form::print(std::ostream& out) const {
	out << "Form " << name << " (signed: " << (isSigned ? "yes" : "no")
		<< ", grade required to sign: " << gradeToSign
		<< ", grade required to execute: " << gradeToExecute << ")";
}

// Overload << operator (utilise print au lieu de friend)
std::ostream& operator<<(std::ostream& out, const Form& form) {
	form.print(out);
	return out;
}
