#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook();
	~PhoneBook();
	bool addContact(const Contact& contact);
	void searchContacts() const;
	int getContactCount() const;
	void removeOldestContact();
	const Contact& getContactByIndex(int index) const;
};

#endif
