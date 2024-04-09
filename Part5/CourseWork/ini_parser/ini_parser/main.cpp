#include <iostream>
#include "IniParser.hpp"

int main()
{
	setlocale(LC_ALL, "RU");
	try {
		IniParser parser{ "ini.txt" };
		auto s1v1 = parser.get_value<double>("Section1.var1");
		std::cout << "Section.var1 value: " + std::to_string(s1v1) << std::endl;
		auto s2v2 = parser.get_value<std::string>("Section2.var21", false);
	}
	catch(std::exception ex){
		std::cout << ex.what();
	}
	
 	return 0;
}