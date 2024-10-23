#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>  // Nécessaire pour std::bad_cast

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
    try {
        // Essayer de caster vers A
        (void)dynamic_cast<A&>(p);  // Cast réussi, utiliser (void) pour indiquer que le résultat est intentionnellement ignoré
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {
        // Si le cast échoue, passer au suivant
    }

    try {
        // Essayer de caster vers B
        (void)dynamic_cast<B&>(p);  // Cast réussi
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {
        // Si le cast échoue, passer au suivant
    }

    try {
        // Essayer de caster vers C
        (void)dynamic_cast<C&>(p);  // Cast réussi
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {
        std::cout << "Unknown type" << std::endl;
    }
}

// Fonction generate qui retourne un pointeur Base* aléatoire vers A, B ou C
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
