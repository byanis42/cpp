#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main() {
	// Test avec un vector
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	try {
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Element found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		easyfind(vec, 100); // Doit lancer une exception
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// Test avec une liste
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);
	lst.push_back(45);

	try {
		std::list<int>::iterator it = easyfind(lst, 25);
		std::cout << "Element found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
