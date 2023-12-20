#include "Leaver.hpp"
#include <iostream>

namespace Leaver {
	void Leaver::leave(const std::string& name) {
		std::cout << "Goodbye, " << name << "!";
	}
}