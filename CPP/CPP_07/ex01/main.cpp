#include <iostream>
#include "iter.hpp"

// Fonction qui affiche un élément
template <typename T>
void print(T &x) {
	std::cout << x << std::endl;
}

// Fonction qui incrémente un élément (valide pour les types numériques)
template <typename T>
void increment(T &x) {
	x += 1;
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original integer array:" << std::endl;
	iter(intArray, 5, print);

	std::cout << "Incremented integer array:" << std::endl;
	iter(intArray, 5, increment);
	iter(intArray, 5, print);

	std::string strArray[] = {"Hello", "World", "42", "C++"};
	std::cout << "Original string array:" << std::endl;
	iter(strArray, 4, print);

	return 0;
}
