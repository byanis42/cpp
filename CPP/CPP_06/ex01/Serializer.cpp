#include "Serializer.hpp"

// Convertit un pointeur Data* en un entier non signé unsigned long
unsigned long Serializer::serialize(Data* ptr) {
	return reinterpret_cast<unsigned long>(ptr);
}

// Convertit un entier non signé unsigned long en un pointeur Data*
Data* Serializer::deserialize(unsigned long raw) {
	return reinterpret_cast<Data*>(raw);
}
