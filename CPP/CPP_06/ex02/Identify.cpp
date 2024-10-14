#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

// Fonction identify avec un pointeur
void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

// Fonction identify avec une référence
void identify(Base& p) {
	// Utiliser un cast manuel pour éviter les exceptions et les variables inutilisées
	Base* ptr = &p;

	if (dynamic_cast<A*>(ptr)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(ptr)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(ptr)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

Base* generate() {
	// Initialiser le générateur aléatoire une seule fois
	static bool initialized = false;
	if (!initialized) {
		srand(time(0));
		initialized = true;
	}

	// Générer un nombre entre 0 et 2
	int random = rand() % 3;

	// Créer un objet de type A, B ou C en fonction du nombre généré
	if (random == 0) {
		return new A();
	} else if (random == 1) {
		return new B();
	} else {
		return new C();
	}
}
