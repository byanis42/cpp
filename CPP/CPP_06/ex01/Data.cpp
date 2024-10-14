#include "Data.hpp"

// Constructeur par défaut
Data::Data() : value(0), name("Unnamed") {
}

// Destructeur
Data::~Data() {
}

// Constructeur de copie
Data::Data(const Data& other) : value(other.value), name(other.name) {
}

// Opérateur d'assignation
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        this->value = other.value;
        this->name = other.name;
    }
    return *this;
}
