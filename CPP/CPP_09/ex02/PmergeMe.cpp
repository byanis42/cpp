#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <limits>

// Constructeur par défaut
PmergeMe::PmergeMe()
{
}

// Constructeur de copie
PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

// Opérateur d'affectation
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vectorSequence = other._vectorSequence;
		this->_dequeSequence = other._dequeSequence;
	}
	return *this;
}

// Destructeur
PmergeMe::~PmergeMe()
{
}

// Fonction pour analyser les entrées et remplir les séquences
void PmergeMe::parseInput(char **argv)
{
	for (int i = 1; argv[i]; ++i)
	{
		std::string arg(argv[i]);
		// Vérifier que chaque caractère est un chiffre
		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (!std::isdigit(arg[j]))
			{
				throw std::runtime_error("Error");
			}
		}
		// Convertir la chaîne en entier
		long number = std::strtol(argv[i], NULL, 10);
		if (number < 0 || number > std::numeric_limits<int>::max())
		{
			throw std::runtime_error("Error");
		}
		_vectorSequence.push_back(static_cast<int>(number));
		_dequeSequence.push_back(static_cast<int>(number));
	}
}

// Fonction pour afficher une séquence (std::vector)
void PmergeMe::printSequence(const std::string &label, const std::vector<int> &sequence) const
{
	std::cout << label;
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}

// Fonction pour afficher une séquence (std::deque)
void PmergeMe::printSequence(const std::string &label, const std::deque<int> &sequence) const
{
	std::cout << label;
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}

// Fonction pour générer la suite de Jacobsthal
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	size_t j = 1;
	while (jacobsthal.back() < n)
	{
		jacobsthal.push_back(jacobsthal[j] + 2 * jacobsthal[j - 1]);
		j++;
	}
	return jacobsthal;
}

// Fonction pour insérer les minima dans la séquence triée des maxima (std::vector)
void PmergeMe::insertMinimaVector(std::vector<int> &sortedMaxima, std::vector<int> &minima)
{
	std::vector<size_t> jacobsthal = generateJacobsthalSequence(minima.size());
	for (size_t i = 0; i < minima.size(); ++i)
	{
		// Calculer l'index d'insertion en utilisant la suite de Jacobsthal
		size_t index = jacobsthal[i + 2] - 1;
		if (index > sortedMaxima.size())
			index = sortedMaxima.size();
		int value = minima[i];
		// Trouver la position d'insertion appropriée
		std::vector<int>::iterator pos = std::lower_bound(sortedMaxima.begin(), sortedMaxima.begin() + index, value);
		// Insérer le minimum à la position appropriée
		sortedMaxima.insert(pos, value);
	}
}

// Fonction pour insérer les minima dans la séquence triée des maxima (std::deque)
void PmergeMe::insertMinimaDeque(std::deque<int> &sortedMaxima, std::deque<int> &minima)
{
	std::vector<size_t> jacobsthal = generateJacobsthalSequence(minima.size());
	for (size_t i = 0; i < minima.size(); ++i)
	{
		// Calculer l'index d'insertion en utilisant la suite de Jacobsthal
		size_t index = jacobsthal[i + 2] - 1;
		if (index > sortedMaxima.size())
			index = sortedMaxima.size();
		int value = minima[i];
		// Trouver la position d'insertion appropriée
		std::deque<int>::iterator pos = std::lower_bound(sortedMaxima.begin(), sortedMaxima.begin() + index, value);
		// Insérer le minimum à la position appropriée
		sortedMaxima.insert(pos, value);
	}
}

// Implémentation de l'algorithme Ford-Johnson pour std::vector
void PmergeMe::fordJohnsonSort(std::vector<int> &sequence)
{
	if (sequence.size() <= 1)
		return;

	// Étape 1 : Création des paires et tri local
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		int first = sequence[i];
		if (i + 1 < sequence.size())
		{
			int second = sequence[i + 1];
			if (first > second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			pairs.push_back(std::make_pair(first, first)); // Gérer l'élément impair
		}
	}

	// Étape 2 : Séparation des maxima et des minima
	std::vector<int> maxima;
	std::vector<int> minima;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		minima.push_back(pairs[i].first);
		maxima.push_back(pairs[i].second);
	}

	// Étape 3 : Tri récursif des maxima
	fordJohnsonSort(maxima);

	// Étape 4 : Insertion des minima en utilisant la suite de Jacobsthal
	insertMinimaVector(maxima, minima);

	// Mise à jour de la séquence originale
	sequence = maxima;
}

// Implémentation de l'algorithme Ford-Johnson pour std::deque
void PmergeMe::fordJohnsonSort(std::deque<int> &sequence)
{
	if (sequence.size() <= 1)
		return;

	// Étape 1 : Création des paires et tri local
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		int first = sequence[i];
		if (i + 1 < sequence.size())
		{
			int second = sequence[i + 1];
			if (first > second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			pairs.push_back(std::make_pair(first, first)); // Gérer l'élément impair
		}
	}

	// Étape 2 : Séparation des maxima et des minima
	std::deque<int> maxima;
	std::deque<int> minima;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		minima.push_back(pairs[i].first);
		maxima.push_back(pairs[i].second);
	}

	// Étape 3 : Tri récursif des maxima
	fordJohnsonSort(maxima);

	// Étape 4 : Insertion des minima en utilisant la suite de Jacobsthal
	insertMinimaDeque(maxima, minima);

	// Mise à jour de la séquence originale
	sequence = maxima;
}

// Fonction pour trier les séquences et mesurer le temps d'exécution
void PmergeMe::sortSequence(char **argv)
{
	try
	{
		parseInput(argv);

		// Afficher la séquence avant le tri
		printSequence("Before: ", _vectorSequence);

		// Mesure du temps pour std::vector
		clock_t startVector = clock();
		fordJohnsonSort(_vectorSequence);
		clock_t endVector = clock();
		double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

		// Mesure du temps pour std::deque
		clock_t startDeque = clock();
		fordJohnsonSort(_dequeSequence);
		clock_t endDeque = clock();
		double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

		// Afficher la séquence après le tri
		printSequence("After:  ", _vectorSequence);

		// Afficher le temps d'exécution pour chaque conteneur
		std::cout << "Time to process a range of " << _vectorSequence.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
		std::cout << "Time to process a range of " << _dequeSequence.size() << " elements with std::deque  : " << timeDeque << " us" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}
