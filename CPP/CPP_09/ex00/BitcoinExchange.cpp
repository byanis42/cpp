#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_exchangeRates = other._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadExchangeRates(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}

	std::string line;
	// Skip the header
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
		{
			continue;
		}

		float rate = std::atof(rateStr.c_str());
		_exchangeRates[date] = rate;
	}

	file.close();
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	if (_exchangeRates.find(date) != _exchangeRates.end())
	{
		return _exchangeRates.at(date);
	}
	else
	{
		// Find the closest previous date
		std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
		if (it != _exchangeRates.begin())
		{
			--it;
			return it->second;
		}
		else
		{
			throw std::runtime_error("Error: date is before available data.");
		}
	}
}
