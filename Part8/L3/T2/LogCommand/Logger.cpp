#include "Logger.hpp"
#include <chrono>

namespace Singleton {
	Logger* logger_inst = nullptr;
}

Logger* Logger::instance()
{
	if (Singleton::logger_inst == nullptr)
		Singleton::logger_inst = new Logger();

	return Singleton::logger_inst;
}

void Logger::add_command(std::shared_ptr<LogCommand> cmd)
{
	m_cmds.push_back(cmd);
}

void Logger::execute_commands()
{
	for (const auto& cmd : m_cmds) {
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::string time = std::ctime(&now_c);
		cmd->print("Current time: " + time);
	}
		
}

void Logger::add_observer(std::shared_ptr<Observer> obs)
{
	m_observers.push_back(obs);
}

void Logger::warning(const std::string& message) const
{
	for (auto& obs : m_observers) {
		obs->onWarning("Log system: " + message);
	}
}

void Logger::error(const std::string& message) const
{
	for (auto& obs : m_observers) {
		obs->onError("Log system: " + message);
	}
}

void Logger::fatal_error(const std::string& message) const
{
	for (auto& obs : m_observers) {
		obs->onFatalError("Log system: " + message);
	}
}