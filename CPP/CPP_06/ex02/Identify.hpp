#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include <iostream>

Base* generate();  // Génère un pointeur vers un objet A, B ou C aléatoirement
void identify(Base* p);  // Identifie le type via un pointeur
void identify(Base& p);  // Identifie le type via une référence

#endif
