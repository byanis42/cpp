#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;  // Déclaration préalable de la classe Bureaucrat

class Form {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	// Exceptions
	class GradeTooHighException : public std::exception {
	private:
		std::string message;
	public:
		GradeTooHighException(const std::string& msg) : message(msg) {}
		virtual ~GradeTooHighException() throw() {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
	};

	class GradeTooLowException : public std::exception {
	private:
		std::string message;
	public:
		GradeTooLowException(const std::string& msg) : message(msg) {}
		virtual ~GradeTooLowException() throw() {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form is not signed";
		}
	};

	// Constructor
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);  // Constructeur de copie
	Form& operator=(const Form& other);  // Opérateur d'affectation
	virtual ~Form();  // Destructeur

	// Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Méthode virtuelle pure à implémenter dans les sous-classes
	virtual void execute(const Bureaucrat& executor) const = 0;

	// Methods
	void beSigned(const Bureaucrat& bureaucrat);

	// Surcharge de l'opérateur <<
	void print(std::ostream& out) const;
};

// Overload << as a non-member function (sans friend)
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif // FORM_HPP
