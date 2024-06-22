#include "Observer.hpp"
#include <iostream>
#include <fstream>

void WarningObserver::onWarning(const std::string& message)
{
	std::cout <<"Warning: " + message << std::endl;
}

void ErrorObserver::onError(const std::string& message)
{
	std::fstream file("Log.txt", std::ios::app);
	if (file.is_open()) {
		file << "Error: " + message << std::endl;
	}
}

void FatalErrorObserver::onFatalError(const std::string& message)
{
	std::fstream file("Log.txt", std::ios::app);
	if (file.is_open()) {
		file << "Fatal error: " + message << std::endl;
	}
	std::cout << "Fatal error: " + message << std::endl;
}