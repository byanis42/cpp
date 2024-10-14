#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	//srand(time(0)); //Initialise le generateur random une fois

	std::cout << "=== Test 1 : Identification via pointeur ===" << std::endl;

	// Générer plusieurs objets aléatoires
	for (int i = 0; i < 5; i++) {
		Base* randomObj = generate();
		std::cout << "Objet généré : ";
		identify(randomObj);
		delete randomObj;  // Nettoyage de l'objet
	}

	std::cout << "\n=== Test 2 : Identification via référence ===" << std::endl;

	// Créer un objet de chaque type et tester par référence
	A a;
	B b;
	C c;

	std::cout << "Objet de type A : ";
	identify(a);  // Doit afficher "A"

	std::cout << "Objet de type B : ";
	identify(b);  // Doit afficher "B"

	std::cout << "Objet de type C : ";
	identify(c);  // Doit afficher "C"

	std::cout << "\n=== Test 3 : Identification via référence avec des objets aléatoires ===" << std::endl;

	// Générer plusieurs objets aléatoires et tester par référence
	for (int i = 0; i < 5; i++) {
		Base* randomObj = generate();
		std::cout << "Objet généré : ";
		identify(*randomObj);
		delete randomObj;  // Nettoyage de l'objet
	}

	return 0;
}
