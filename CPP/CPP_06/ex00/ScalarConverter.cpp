#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>  // Pour strtod, strtof, strtol
#include <cerrno>   // Pour errno, ERANGE
#include <cmath>    // Pour isnan, isinf

void ScalarConverter::convert(const std::string& literal) {
	char* end;
	errno = 0;

	// Gestion des pseudo-littéraux (infinis, NaN) en priorité
	if (literal == "nan" || literal == "nanf") {
		printSpecial("nan");
		return;
	} else if (literal == "+inf" || literal == "+inff") {
		printSpecial("+inf");
		return;
	} else if (literal == "-inf" || literal == "-inff") {
		printSpecial("-inf");
		return;
	}

	// Tentative de conversion en int
	long intValue = strtol(literal.c_str(), &end, 10);
	if (*end == '\0') {
		if (errno == ERANGE || intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max()) {
			std::cout << "int: impossible (overflow)" << std::endl;
		} else {
			// Gestion des valeurs Non displayable pour char
			if (intValue >= 0 && intValue <= 127 && std::isprint(intValue)) {
				std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
			} else if (intValue >= 0 && intValue <= 127) {
				std::cout << "char: Non displayable" << std::endl;
			} else {
				std::cout << "char: impossible" << std::endl;
			}

			std::cout << "int: " << intValue << std::endl;

			// Conversion en float
			if (intValue > std::numeric_limits<float>::max()) {
				std::cout << "float: impossible" << std::endl;
			} else {
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f" << std::endl;
			}

			std::cout << "double: " << static_cast<double>(intValue) << std::endl;
		}
		return;
	}

	// Tentative de conversion en float
	float floatValue = strtof(literal.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		if (errno == ERANGE || floatValue < -std::numeric_limits<float>::max() || floatValue > std::numeric_limits<float>::max()) {
			std::cout << "float: impossible (overflow)" << std::endl;
		} else {
			printConversions(static_cast<double>(floatValue));
		}
		return;
	}

	// Tentative de conversion en double
	double doubleValue = strtod(literal.c_str(), &end);
	if (*end == '\0') {
		if (errno == ERANGE || doubleValue < -std::numeric_limits<double>::max() || doubleValue > std::numeric_limits<double>::max()) {
			std::cout << "double: impossible (overflow)" << std::endl;
		} else {
			printConversions(doubleValue);
		}
		return;
	}

	// Gestion des littéraux char
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		char charValue = literal[0];
		printConversions(static_cast<double>(charValue));
	} else {
		std::cerr << "Invalid literal: " << literal << std::endl;
	}
}



void ScalarConverter::printConversions(double value) {
	// Conversion en char
	if (std::isnan(value) || value < 0 || value > 127 || !std::isprint(static_cast<int>(value))) {
		std::cout << "char: impossible" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}

	// Conversion en int
	if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}

	// Conversion en float
	if (std::isnan(value)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	} else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}

	// Conversion en double
	if (std::isnan(value)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	} else if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void ScalarConverter::printSpecial(const std::string& special) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << special << "f" << std::endl;
	std::cout << "double: " << special << std::endl;
}
