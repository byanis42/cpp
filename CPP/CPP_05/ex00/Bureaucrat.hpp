#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>  // Nécessaire pour std::ostringstream

class Bureaucrat {
private:
	const std::string name;
	int grade;

public:
	// Orthodox Canonical Form
	Bureaucrat();  // Constructeur par défaut
	Bureaucrat(const Bureaucrat& other);  // Constructeur de copie
	Bureaucrat& operator=(const Bureaucrat& other);  // Opérateur d'affectation
	~Bureaucrat();  // Destructeur

	// Constructeur avec paramètres
	Bureaucrat(const std::string& name, int grade);

	// Exceptions
	class GradeTooHighException : public std::exception {
	private:
		std::string message;
	public:
		GradeTooHighException(int grade) {
			std::ostringstream oss;
			oss << "Grade too high: " << grade;
			message = oss.str();
		}
		virtual ~GradeTooHighException() throw() {}

		virtual const char* what() const throw() {
			return message.c_str();
		}
	};

	class GradeTooLowException : public std::exception {
	private:
		std::string message;
	public:
		GradeTooLowException(int grade) {
			std::ostringstream oss;
			oss << "Grade too low: " << grade;
			message = oss.str();
		}
		virtual ~GradeTooLowException() throw() {}

		virtual const char* what() const throw() {
			return message.c_str();
		}
	};

	// Getters
	const std::string& getName() const;
	int getGrade() const;

	// Methods to modify grade
	void incrementGrade();
	void decrementGrade();

	// Overload operator as member function
	void print(std::ostream& out) const;
};

// Overload << as a non-member, non-friend function
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
