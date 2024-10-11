#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> intArray(5);

	// Initialisation des éléments
	for (size_t i = 0; i < intArray.size(); i++) {
		intArray[i] = i * 2;
	}

	// Affichage des éléments
	std::cout << "Integer array:" << std::endl;
	for (size_t i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << std::endl;
	}

	// Test de la copie
	Array<int> copyArray = intArray;
	std::cout << "Copied array:" << std::endl;
	for (size_t i = 0; i < copyArray.size(); i++) {
		std::cout << copyArray[i] << std::endl;
	}

	// Test de la gestion des exceptions
	try {
		std::cout << intArray[10] << std::endl;  // Devrait lever une exception
	} catch (std::out_of_range &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test avec un tableau de chaînes
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "42";

	std::cout << "String array:" << std::endl;
	for (size_t i = 0; i < strArray.size(); i++) {
		std::cout << strArray[i] << std::endl;
	}

	return 0;
}
