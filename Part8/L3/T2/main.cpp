#include <iostream>
#include "LogCommand/Logger.hpp"

int main() {
	auto logger = Logger::instance();
	auto clc = std::make_shared<ConsoleLogCommand>();
	logger->add_command(clc);
	auto flc = std::make_shared<FileLogCommand>();
	logger->add_command(flc);
	logger->execute_commands();

	auto w_obs = std::make_shared<WarningObserver>();
	logger->add_observer(w_obs);
	auto e_obs = std::make_shared<ErrorObserver>();
	logger->add_observer(e_obs);
	auto fe_obs = std::make_shared<FatalErrorObserver>();
	logger->add_observer(fe_obs);

	logger->warning("Warning message function test");
	logger->error("Error message function test");
	logger->fatal_error("Fatal error message function test");

	return 0;
}