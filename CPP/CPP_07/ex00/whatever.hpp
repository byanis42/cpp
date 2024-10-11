#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Template pour swap: échange les valeurs de deux variables
template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

// Template pour min: renvoie la plus petite des deux valeurs
template <typename T>
const T &min(const T &a, const T &b) {
	return (a < b ? a : b);
}

// Template pour max: renvoie la plus grande des deux valeurs
template <typename T>
const T &max(const T &a, const T &b) {
	return (a > b ? a : b);
}

#endif // WHATEVER_HPP
