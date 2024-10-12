#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm> // pour std::sort, std::min_element, std::max_element
#include <exception> // pour std::exception
#include <iostream>  // pour std::cout
#include <stdexcept> // pour std::out_of_range
#include <iterator>  // pour std::distance

class Span {
public:
	Span(unsigned int N) : _maxSize(N) {}

	// Fonction pour ajouter un nombre dans le container
	void addNumber(int number) {
		if (_numbers.size() >= _maxSize)
			throw std::out_of_range("Span is full, cannot add more numbers.");
		_numbers.push_back(number);
	}

	// Fonction pour ajouter plusieurs nombres d'une seule fois
	template<typename Iterator>
	void addNumbers(Iterator begin, Iterator end) {
		if (std::distance(begin, end) + _numbers.size() > _maxSize)
			throw std::out_of_range("Span will exceed its capacity.");
		_numbers.insert(_numbers.end(), begin, end);
	}

	// Fonction pour trouver la plus petite distance (span)
	int shortestSpan() const {
		if (_numbers.size() < 2)
			throw std::logic_error("Not enough numbers to calculate span.");

		// Copie des nombres et tri
		std::vector<int> sorted = _numbers;
		std::sort(sorted.begin(), sorted.end());

		// Calcul du plus petit écart consécutif
		int minSpan = sorted[1] - sorted[0];
		for (unsigned int i = 1; i < sorted.size() - 1; ++i) {
			int span = sorted[i + 1] - sorted[i];
			if (span < minSpan)
				minSpan = span;
		}
		return minSpan;
	}

	// Fonction pour trouver la plus grande distance (span)
	int longestSpan() const {
		if (_numbers.size() < 2)
			throw std::logic_error("Not enough numbers to calculate span.");

		// Chercher les éléments min et max
		int minNumber = *std::min_element(_numbers.begin(), _numbers.end());
		int maxNumber = *std::max_element(_numbers.begin(), _numbers.end());

		return maxNumber - minNumber;
	}

private:
	std::vector<int> _numbers;   // Container pour stocker les nombres
	unsigned int _maxSize;       // Capacité maximale du Span
};

#endif
