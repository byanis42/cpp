#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::addContact(const Contact& contact) {
	if (contactCount >= 8) {
		std::cout << "Le Phonebook est plein. Le contact le plus vieux sera remplacé." << std::endl;
		return false;
	}

	contacts[contactCount] = contact;
	contactCount++;
	return true;
}

void PhoneBook::searchContacts() const {
	std::cout << "|  Index  |First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < contactCount; ++i) {
		std::cout << "|";
		std::cout << std::setw(9) << i + 1 << "|";
		std::cout << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
}

int PhoneBook::getContactCount() const {
	return contactCount;
}

const Contact& PhoneBook::getContactByIndex(int index) const {
	if (index >= 0 && index < contactCount) {
		return contacts[index];
	} else {
		throw std::out_of_range("Index out of range");
	}
}

void PhoneBook::removeOldestContact() {
	if (contactCount <= 0) {
		std::cout << "Aucun contact à supprimer." << std::endl;
		return;
	}

	for (int i = 0; i < contactCount - 1; ++i) {
		contacts[i] = contacts[i + 1];
	}

	contactCount--;
}
