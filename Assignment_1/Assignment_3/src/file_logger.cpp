#include "../include/file_logger.hpp"

FileLogger::FileLogger(std::string filename)
{
	this->filename = filename;
}

void FileLogger::log(const std::string msg)
{
	logfile.open(this->filename, std::ios::app);
	logfile << msg << std::endl;
	logfile.close();
}
