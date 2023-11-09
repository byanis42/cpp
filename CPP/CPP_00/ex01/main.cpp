#include <iostream>
#include "PhoneBook.hpp"

int to_int(const char *s) {
	if (s == NULL || *s == '\0')
		return 0;

	bool negate = (s[0] == '-');
	if (*s == '+' || *s == '-')
		++s;

	if (*s == '\0')
		return 0;

	int result = 0;
	while (*s) {
		if (*s < '0' || *s > '9')
			return 0;
		result = result * 10 - (*s - '0');
		++s;
	}
	return negate ? result : -result;
}

int main() {
	PhoneBook phonebook;

	int choice;
	std::string tmp_s;
	while (true) {
		std::cout << "PhoneBook - Menu:" << std::endl;
		std::cout << "1. Ajouter un contact (ADD)" << std::endl;
		std::cout << "2. Afficher les contacts (SEARCH)" << std::endl;
		std::cout << "3. Quitter (EXIT)" << std::endl;

		std::cout << "Choisissez une option (1/2/3): ";
		std::getline(std::cin, tmp_s);
		choice = to_int(tmp_s.c_str());

		if (std::cin.eof()) {
			break;
		}

		switch (choice) {
			case 1: {
				if (phonebook.getContactCount() >= 8) {
					std::cout << "Le phonebook est plein. Le contact le plus vieux sera supprimé." << std::endl;
					phonebook.removeOldestContact();
				}

				Contact contact;
				std::string input;

				do {
					std::cout << "Prénom : ";
					std::getline(std::cin, input);
					if (input.empty()) {
						std::cout << "Les sections du phonebook ne peuvent pas être vides. Réessayez." << std::endl;
					}
				} while (input.empty());
				contact.setFirstName(input);

				do {
					std::cout << "Nom : ";
					std::getline(std::cin, input);
					if (input.empty()) {
						std::cout << "Les sections du phonebook ne peuvent pas être vides. Réessayez." << std::endl;
					}
				} while (input.empty());
				contact.setLastName(input);

				do {
					std::cout << "Surnom : ";
					std::getline(std::cin, input);
					if (input.empty()) {
						std::cout << "Les sections du phonebook ne peuvent pas être vides. Réessayez." << std::endl;
					}
				} while (input.empty());
				contact.setNickname(input);

				do {
					std::cout << "Numéro de téléphone : ";
					std::getline(std::cin, input);
					if (input.empty()) {
						std::cout << "Les sections du phonebook ne peuvent pas être vides. Réessayez." << std::endl;
					}
				} while (input.empty());
				contact.setPhoneNumber(input);

				do {
					std::cout << "Secret le plus sombre : ";
					std::getline(std::cin, input);
					if (input.empty()) {
						std::cout << "Les sections du phonebook ne peuvent pas être vides. Réessayez." << std::endl;
					}
				} while (input.empty());
				contact.setDarkestSecret(input);

				phonebook.addContact(contact);

				std::cout << "Contact ajouté avec succès !" << std::endl;
				break;
			}
			case 2:{
				if (phonebook.getContactCount() > 0) {
					phonebook.searchContacts();
					int index;

					do {
						std::cout << "Saisissez l'index de l'entrée à afficher (1-" << phonebook.getContactCount() << "): ";
						std::getline(std::cin, tmp_s);
						index = to_int(tmp_s.c_str());
					} while (index < 1 || index > phonebook.getContactCount());

					const Contact& selectedContact = phonebook.getContactByIndex(index - 1);
					std::cout << "Détails de l'entrée (index " << index << "):" << std::endl;
					std::cout << "Prénom : " << selectedContact.getFirstName() << std::endl;
					std::cout << "Nom : " << selectedContact.getLastName() << std::endl;
					std::cout << "Surnom : " << selectedContact.getNickname() << std::endl;
					std::cout << "Numéro de téléphone : " << selectedContact.getPhoneNumber() << std::endl;
					std::cout << "Secret le plus sombre : " << selectedContact.getDarkestSecret() << std::endl;
				} else {
					std::cout << "Le Phonebook est vide. Rien à afficher." << std::endl;
				}
				break;
			}
			case 3:
				std::cout << "Au revoir !" << std::endl;
				return 0;
			default:
				std::cout << "Option invalide. Veuillez choisir une option valide (1/2/3)." << std::endl;
				std::cin.clear();
				break;
		}
	}
	return 0;
}
