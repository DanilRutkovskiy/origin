#include <iostream>
#include "Leaver.hpp"

int main() {
	std::cout << "Enter name: ";
	std::string name;
	std::cin >> name;
	Leaver::Leaver leaver_obj;
	leaver_obj.leave(name);
	return 0;
}