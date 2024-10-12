#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
	std::ifstream file(databaseFile.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	while (getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		float rate;

		if (getline(ss, date, ',') && (ss >> rate)) {
			_exchangeRates[date] = rate;
		}
	}
	file.close();
}

void BitcoinExchange::processFile(const std::string& inputFile) {
	std::ifstream file(inputFile.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true; // Pour ignorer la première ligne "date | value"
	while (getline(file, line)) {
		if (firstLine) {
			// Ignorer la première ligne qui contient les titres
			firstLine = false;
			continue;
		}

		// Supprimer les espaces en début et fin de ligne
		line.erase(0, line.find_first_not_of(" \t"));
		line.erase(line.find_last_not_of(" \t") + 1);

		// Vérifier si la ligne contient le séparateur " | "
		size_t sepPos = line.find('|');
		if (sepPos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sepPos);
		std::string valueStr = line.substr(sepPos + 1);

		// Supprimer les espaces autour du séparateur " | "
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		// Convertir la valeur en float
		float value = std::atof(valueStr.c_str());
		if (!isValidValue(value)) {
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
			} else {
				std::cerr << "Error: too large a number." << std::endl;
			}
			continue;
		}

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		handleLine(date, value);
	}
	file.close();
}

void BitcoinExchange::handleLine(const std::string& date, float value) {
	float rate = getClosestRate(date);
	std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

float BitcoinExchange::getClosestRate(const std::string& date) {
	std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.begin()) {
		return it->second;
	}
	if (it == _exchangeRates.end() || it->first != date) {
		--it;
	}
	return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (std::exception& e) {
		return false;
	}

	if (year < 2009 || year > 2024) { // Bitcoin n'existait pas avant 2009
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (day < 1 || day > 31) {
		return false;
	}

	// Vérification simpliste du nombre de jours dans chaque mois (sans gérer les années bissextiles)
	static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day > daysInMonth[month - 1]) {
		return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(float value) {
	return value >= 0.0f && value <= 1000.0f;
}
