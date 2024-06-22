#include "LogMessage.hpp"
#include <iostream>
#include <fstream>
#include <exception>

LogMessage::LogMessage(std::string message, Type type) : m_message{message}, m_type{type}
{
}

Type LogMessage::type() const
{
	return m_type;
}

const std::string& LogMessage::message() const
{
	return m_message;
}

void WarningLogMessageHandler::setNextHandler(LogMessageHandler* handler)
{
	m_handler = handler;
}

void WarningLogMessageHandler::handleRequest(LogMessage* message)
{
	if (message->type() == Type::Warning) {
		std::cout << "WarningLogMessageHandler: " << message->message();
	}
	else {
		if (m_handler != nullptr) {
			m_handler->handleRequest(message);
		}
	}
}

void ErrorLogMessageHandler::setNextHandler(LogMessageHandler* handler)
{
	m_handler = handler;
}

void ErrorLogMessageHandler::handleRequest(LogMessage* message)
{
	if (message->type() == Type::Error) {
		std::string str = "ErrorLogMessageHandler: " + message->message();
		std::ofstream file{ "Log.txt", std::ios_base::app };
		if (file.is_open()) {
			file << message << std::endl;
		}
	}
	else {
		if (m_handler != nullptr) {
			m_handler->handleRequest(message);
		}
	}
}

void FatalErrorLogMessageHandler::setNextHandler(LogMessageHandler* handler)
{
	m_handler = handler;
}

void FatalErrorLogMessageHandler::handleRequest(LogMessage* message)
{
	if (message->type() == Type::FatalError) {
		std::string str = "FatalErrorLogMessageHandler: " + message->message();

		std::runtime_error ex{ str };
		throw ex;
	}
	else {
		if (m_handler != nullptr) {
			m_handler->handleRequest(message);
		}
	}
}

void UnknownLogMessageHandler::setNextHandler(LogMessageHandler* handler)
{
	m_handler = handler;
}

void UnknownLogMessageHandler::handleRequest(LogMessage* message)
{
	if (message->type() == Type::UnknownMessage) {
		std::string str = "UnknownLogMessageHandler: " + message->message();

		std::runtime_error ex{ str };
		throw ex;
	}
	else {
		if (m_handler != nullptr) {
			m_handler->handleRequest(message);
		}
	}
}