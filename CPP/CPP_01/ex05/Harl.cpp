#include "Harl.hpp"
#include <iostream>
#include <map>

void Harl::debug() {
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	typedef void (Harl::*LevelFunc)();
	std::map<std::string, LevelFunc> levelFuncs;

	levelFuncs["DEBUG"] = &Harl::debug;
	levelFuncs["INFO"] = &Harl::info;
	levelFuncs["WARNING"] = &Harl::warning;
	levelFuncs["ERROR"] = &Harl::error;

	std::map<std::string, LevelFunc>::iterator it = levelFuncs.find(level);
	if (it != levelFuncs.end()) {
		(this->*it->second)();
	}
}
