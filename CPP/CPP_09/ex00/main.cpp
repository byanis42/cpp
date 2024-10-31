#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

bool isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false; // February is assumed to have 31 days

	return true;
}

bool isValidValue(const std::string &valueStr, float &value)
{
	char *endptr = NULL;
	value = std::strtof(valueStr.c_str(), &endptr);
	if (*endptr != '\0' && *endptr != '\n')
		return false;
	if (value < 0)
		return false;
	if (value > 1000)
		return false;
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btcExchange;
	try
	{
		btcExchange.loadExchangeRates("data.csv");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::string line;
	// Skip the header if present
	std::getline(inputFile, line);
	if (line.find("date | value") == std::string::npos)
	{
		inputFile.seekg(0);
	}

	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Trim whitespace
		date.erase(date.find_last_not_of(" \n\r\t") + 1);
		date.erase(0, date.find_first_not_of(" \n\r\t"));
		valueStr.erase(valueStr.find_last_not_of(" \n\r\t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		float value = 0.0f;
		if (!isValidValue(valueStr, value))
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		try
		{
			float rate = btcExchange.getExchangeRate(date);
			float result = value * rate;
			std::cout << date << " => " << valueStr << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	inputFile.close();
	return 0;
}
