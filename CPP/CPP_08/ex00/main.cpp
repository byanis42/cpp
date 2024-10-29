#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

void testVector() {
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i * 2); // Remplit avec des nombres pairs: 0, 2, 4, ...
	}

	try {
		std::cout << "Test vector - Found: " << *easyfind(vec, 6) << std::endl;
		std::cout << "Test vector - Found: " << *easyfind(vec, 3) << std::endl; // Doit lancer une exception
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testList() {
	std::list<int> lst;
	for (int i = 0; i < 10; ++i) {
		lst.push_back(i);
	}

	try {
		std::cout << "Test list - Found: " << *easyfind(lst, 9) << std::endl;
		std::cout << "Test list - Found: " << *easyfind(lst, -1) << std::endl; // Doit lancer une exception
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testDeque() {
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	try {
		std::cout << "Test deque - Found: " << *easyfind(dq, 20) << std::endl;
		std::cout << "Test deque - Found: " << *easyfind(dq, 100) << std::endl; // Doit lancer une exception
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	testVector();
	testList();
	testDeque();
	return 0;
}
