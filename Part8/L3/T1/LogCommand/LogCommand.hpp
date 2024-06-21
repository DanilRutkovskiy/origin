#pragma once
#include<string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) const = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    virtual void print(const std::string& message) const override;
};

class FileLogCommand : public LogCommand {
public:
    virtual void print(const std::string& message) const override;
};