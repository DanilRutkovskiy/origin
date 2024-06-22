#include <iostream>
#include "LogCommand/Logger.hpp"
#include "LogCommand/LogMessage.hpp"
#include <exception>

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
	
	LogMessage wm{ "Warning Message", Type::Warning };
	LogMessage em{ "Error Message", Type::Error };
	LogMessage fem{ "Fatal Error Message", Type::FatalError };
	LogMessage um{ "Unknown Message", Type::UnknownMessage };

	WarningLogMessageHandler* wlmh = new WarningLogMessageHandler();
	ErrorLogMessageHandler* elmh = new ErrorLogMessageHandler();
	wlmh->setNextHandler(elmh);
	FatalErrorLogMessageHandler* felmh = new FatalErrorLogMessageHandler();
	elmh->setNextHandler(felmh);
	UnknownLogMessageHandler* ulmh = new UnknownLogMessageHandler();
	felmh->setNextHandler(ulmh);

	try {
		wlmh->handleRequest(&wm);
		wlmh->handleRequest(&em);
		wlmh->handleRequest(&fem);
		wlmh->handleRequest(&um);
	}
	catch(std::exception ex) {
		std::cout << ex.what();
	}
	

	return 0;
}