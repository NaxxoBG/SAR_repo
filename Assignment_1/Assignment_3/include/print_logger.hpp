#pragma once
#include <string>
#include <iostream>

using namespace std;

#include "logger.hpp"

class PrintLogger : public Logger
{
public:

    virtual void log(std::string msg) override;
};

