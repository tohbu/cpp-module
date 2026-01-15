#include "Harl.hpp"
#include <map>
#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

Harl::Harl(){};

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG_MSG << std ::endl
			  << std::endl;
}
void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO_MSG << std::endl
			  << std::endl;
}
void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING_MSG << std::endl
			  << std::endl;
}
void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR_MSG << std::endl
			  << std::endl;
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			switch (i)
			{
				case 0:
					this->debug();
					// fall through
				case 1:
					this->info();
					// fall through
				case 2:
					this->warning();
					// fall through
				case 3:
					this->error();
					// fall through
			}
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return;
}