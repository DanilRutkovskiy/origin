#pragma once
#include <string>
#include "LogMessage.hpp"
class Observer {
public:
    virtual void onWarning(const std::string& message) {};
    virtual void onError(const std::string& message) {};
    virtual void onFatalError(const std::string& message) {};
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override;
};

class ErrorObserver : public Observer {
public:
    void onError(const std::string& message) override;
};

class FatalErrorObserver : public Observer {
public:
    void onFatalError(const std::string& message) override;
};