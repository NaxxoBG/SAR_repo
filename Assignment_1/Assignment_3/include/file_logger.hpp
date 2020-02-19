#pragma once
#include <string>

#include "logger.hpp"
#include "fstream"

class FileLogger : public Logger
{
public:
    FileLogger(std::string filename);

    virtual void log(std::string msg) override;

private:
    std::ofstream logfile;
	std::string filename;
};