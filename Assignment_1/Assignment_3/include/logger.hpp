#pragma once
#include <string>

class Logger
{
public:
    virtual void log(std::string msg) = 0;

    virtual ~Logger() {};
};