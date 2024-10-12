#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return 1;
	}

	BitcoinExchange btc("data.csv");
	btc.processFile(argv[1]);

	return 0;
}
