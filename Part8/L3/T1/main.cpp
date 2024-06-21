#include <iostream>
#include "LogCommand/LogCommand.hpp"
#include <chrono>
#include <ctime>

void print(const LogCommand& cmd) {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::string time = std::ctime(&now_c);
	cmd.print("Current time: " + time);
}

int main() {
	ConsoleLogCommand ccmd;
	FileLogCommand fcmd;
	print(ccmd);
	print(fcmd);
	return 0;
}