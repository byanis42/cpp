#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

// La classe MutantStack hérite publiquement de std::stack
template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Utiliser le type du container sous-jacent à std::stack
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
	MutantStack<T>& operator=(const MutantStack<T>& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {}

	// Retourner un itérateur vers le début de la pile
	iterator begin() {
		return this->c.begin();
	}

	// Retourner un itérateur vers la fin de la pile
	iterator end() {
		return this->c.end();
	}
};

#endif
