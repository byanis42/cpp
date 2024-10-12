#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, float> _exchangeRates;

	public:
		BitcoinExchange(const std::string& databaseFile);
		~BitcoinExchange() {}

		void processFile(const std::string& inputFile);
		void handleLine(const std::string& date, float value);
		float getClosestRate(const std::string& date);
		bool isValidDate(const std::string& date);
		bool isValidValue(float value);
};

#endif
