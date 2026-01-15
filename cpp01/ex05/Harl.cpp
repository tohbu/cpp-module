#include "Harl.hpp"
#include <map>
#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

Harl::Harl()
{
	_pFunc[0] = &Harl::debug;
	_pFunc[1] = &Harl::info;
	_pFunc[2] = &Harl::warning;
	_pFunc[3] = &Harl::error;
};

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << DEBUG_MSG << std ::endl;
}
void Harl::info()
{
	std::cout << INFO_MSG << std::endl;
}
void Harl::warning()
{
	std::cout << WARNING_MSG << std::endl;
}
void Harl::error()
{
	std::cout << ERROR_MSG << std::endl;
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*_pFunc[i])();
			return;
		}
	}
	std::cout << "no level" << std::endl;
	return;
}