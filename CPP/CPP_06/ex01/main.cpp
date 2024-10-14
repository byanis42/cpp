#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	// Création d'un objet Data
	Data original;
	original.value = 42;
	original.name = "Test Object";

	// Sérialisation
	unsigned long raw = Serializer::serialize(&original);
	std::cout << "Adresse originale: " << &original << std::endl;
	std::cout << "Valeur sérialisée: " << raw << std::endl;

	// Désérialisation
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Adresse désérialisée: " << deserialized << std::endl;

	// Vérification que l'objet récupéré est bien le même
	if (deserialized == &original) {
		std::cout << "Les objets sont identiques après désérialisation." << std::endl;
		std::cout << "Value: " << deserialized->value << ", Name: " << deserialized->name << std::endl;
	} else {
		std::cout << "Erreur: l'objet désérialisé est différent." << std::endl;
	}

	return 0;
}
