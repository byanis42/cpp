#include "Bureaucrat.hpp"

// Constructeur par défaut
Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {
	// Par défaut, un bureaucrate a un nom "Unnamed" et le grade le plus bas.
}

// Constructeur de copie
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	// Copie les attributs de l'autre bureaucrate.
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		if (other.grade < 1) {
			throw GradeTooHighException(other.grade);
		} else if (other.grade > 150) {
			throw GradeTooLowException(other.grade);
		}
		this->grade = other.grade;
	}
	return *this;
}

// Destructeur
Bureaucrat::~Bureaucrat() {}

// Constructeur avec paramètres
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException(grade);
	} else if (grade > 150) {
		throw GradeTooLowException(grade);
	}
}

// Getters
const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

// Methods to modify grade
void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1) {
		throw GradeTooHighException(grade - 1);
	}
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150) {
		throw GradeTooLowException(grade + 1);
	}
	grade++;
}

// Print function to use inside operator<< overload
void Bureaucrat::print(std::ostream& out) const {
	out << name << ", bureaucrat grade " << grade;
}

// Non-member, non-friend operator<< overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	b.print(out);
	return out;
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
