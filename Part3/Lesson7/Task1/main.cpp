#include <iostream>
#include<exception>

class bad_length : public std::exception {
	virtual const char* what() const noexcept override {
		return "Bad length of the string\0";
	}
};

size_t function(std::string str, size_t forbidden_length) {
	if (str.size() == forbidden_length) {
		bad_length except;
		throw except;
	}
	else {
		return str.size();
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	size_t f_l = 0;
	std::cout << "Введите запретную длину: ";
	std::cin >> f_l;
	std::cout << "Введите слово: ";
	std::string str;
	std::cin >> str;
	try{ 
		std::cout << "Длина слова \"" << str << "\" равна " << function(str, f_l);
	}
	catch (bad_length) {
		std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
	}
	return 0;
}