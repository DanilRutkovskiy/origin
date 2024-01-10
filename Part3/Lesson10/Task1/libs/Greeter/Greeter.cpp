#include "Greeter.hpp"
#include <iostream>
namespace GreeterNS {
	void Greeter::greet(const std::string& name) {
		std::cout << "Hello, " << name << "!";
	}
}