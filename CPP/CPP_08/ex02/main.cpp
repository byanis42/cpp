#include "MutantStack.hpp"
#include <iostream>

int main() {
	// Test de MutantStack avec des entiers
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top of stack: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Itération sur les éléments de la stack
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Test de la copie d'une pile
	std::stack<int> s(mstack);

	return 0;
}
