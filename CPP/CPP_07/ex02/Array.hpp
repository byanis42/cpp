#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
	private:
		T *array;
		size_t len;

	public:
		// Constructeur par défaut : crée un tableau vide
		Array() : array(new T[0]), len(0) {}

		// Constructeur avec taille : crée un tableau de n éléments initialisés par défaut
		Array(unsigned int n) : array(new T[n]), len(n) {}

		// Constructeur par copie
		Array(const Array &other) : array(new T[other.len]), len(other.len) {
			for (size_t i = 0; i < len; i++) {
				array[i] = other.array[i];
			}
		}

		// Destructeur
		~Array() {
			delete[] array;
		}

		// Opérateur d'affectation
		Array &operator=(const Array &other) {
			if (this != &other) {
				delete[] array;
				array = new T[other.len];
				len = other.len;
				for (size_t i = 0; i < len; i++) {
					array[i] = other.array[i];
				}
			}
			return *this;
		}

		// Accès aux éléments avec gestion des exceptions
		T &operator[](size_t index) {
			if (index >= len) {
				throw std::out_of_range("Index out of bounds");
			}
			return array[index];
		}

		// Accès aux éléments en lecture seule (pour les objets const)
		const T &operator[](size_t index) const {
			if (index >= len) {
				throw std::out_of_range("Index out of bounds");
			}
			return array[index];
		}

		// Fonction size : retourne la taille du tableau
		size_t size() const {
			return len;
		}
};

#endif // ARRAY_HPP
