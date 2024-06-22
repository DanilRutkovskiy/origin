#pragma once
#include <string>

enum class Type {
    Warning,
    Error,
    FatalError,
    UnknownMessage
};

class LogMessage {
public:
    LogMessage(const std::string message, Type type);
public:
    Type type() const;
    const std::string& message() const;

private:
    Type m_type;
    std::string m_message;
};

class LogMessageHandler {
public:
    virtual void setNextHandler(LogMessageHandler* handler) = 0;
    virtual void handleRequest(LogMessage* message) = 0;

protected:
    LogMessageHandler* m_handler = nullptr;
};

class WarningLogMessageHandler : public LogMessageHandler {
public:
    void setNextHandler(LogMessageHandler* handler) override;
    virtual void handleRequest(LogMessage* message) override;
};

class ErrorLogMessageHandler : public LogMessageHandler {
public:
    void setNextHandler(LogMessageHandler* handler) override;
    virtual void handleRequest(LogMessage* message) override;
};

class FatalErrorLogMessageHandler : public LogMessageHandler {
public:
    void setNextHandler(LogMessageHandler* handler) override;
    virtual void handleRequest(LogMessage* message) override;
};

class UnknownLogMessageHandler : public LogMessageHandler {
public:
    void setNextHandler(LogMessageHandler* handler) override;
    virtual void handleRequest(LogMessage* message) override;
};