#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	public:
		// Méthode statique principale pour convertir un littéral
		static void convert(const std::string& literal);

	private:
		// Méthodes d'aide pour les conversions et affichages
		static void printConversions(double value);
		static void printSpecial(const std::string& special);

		// Constructeur privé pour interdire l'instanciation
		ScalarConverter();
		~ScalarConverter();
};

#endif
