#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <map>
#include <iostream>
enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

class Harl
{
private:
	void debug();
	void info();
	void warning();
	void error();

public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif