#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // pour std::find
#include <iterator>  // pour std::distance
#include <exception> // pour std::exception
#include <iostream>

// Exception si l'élément n'est pas trouvé
class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return "Element not found in the container";
	}
};

// Fonction template easyfind qui prend un container et un entier à chercher
template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
}

#endif
