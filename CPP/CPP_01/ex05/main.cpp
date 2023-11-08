#include "Harl.hpp"
#include <iostream>
#include <string>

int main() {
	Harl harl;

	while (true) {
		std::string input;
		std::cout << "Enter a log level (DEBUG, INFO, WARNING, ERROR) or 'exit' to quit: ";

		std::getline(std::cin, input);

		if (std::cin.eof()) {
			break;
		}

		if (input == "exit") {
			break;
		}

		harl.complain(input);
	}

	return 0;
}
