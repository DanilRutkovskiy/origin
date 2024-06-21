#include "LogCommand.hpp"
#include <iostream>
#include <fstream>

void ConsoleLogCommand::print(const std::string& message) const {	
	std::cout << "Log: " << message << std::endl;
}

void FileLogCommand::print(const std::string& message) const {
	std::ofstream file{ "Log.txt" };

	if (file.is_open()) {
		file << "Log: " << message << std::endl;
	}
	else {
		std::cout << "Can't open log file!" << std::endl;
	}
}