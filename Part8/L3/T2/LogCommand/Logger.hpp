#pragma once
#include "LogCommand.hpp"
#include "Observer.hpp"
#include <memory>
#include <vector>

class Logger {
public:
	static Logger* instance();
public:
	void add_command(std::shared_ptr<LogCommand> cmd);
	void execute_commands();

	void add_observer(std::shared_ptr<Observer> obs);

	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void fatal_error(const std::string& message) const;

private:
	Logger() {};
	Logger(Logger&) = delete;
	void operator =(Logger&) = delete;
private:
	std::vector<std::shared_ptr<LogCommand>> m_cmds;
	std::vector<std::shared_ptr<Observer>> m_observers;
};

namespace Singleton {
}