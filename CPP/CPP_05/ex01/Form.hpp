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

	// Constructor
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);  // Constructeur de copie
	Form& operator=(const Form& other);  // Opérateur d'affectation
	~Form();  // Destructeur

	// Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Methods
	void beSigned(const Bureaucrat& bureaucrat);

	// Nouvelle méthode pour la surcharge de l'opérateur <<
	void print(std::ostream& out) const;
};

// Overload << as a non-member function (sans friend)
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
