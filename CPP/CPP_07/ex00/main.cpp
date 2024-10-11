#include <iostream>
#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;

	std::cout << "a before swap = " << a << std::endl;
	std::cout << "b before swap = " << b << std::endl;
	std::cout << "-----swapping a & b-----" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	std::cout << "c beofre swap = \"string1\"" << std::endl;
	std::cout << "d beofre swap = \"string2\"" << std::endl;

	std::cout << "-----swapping c & d-----" << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return 0;
}
