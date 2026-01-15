#include "Harl.hpp"
#include <iostream>
#include <string>

int main()
{
	Harl h;
	std::string read_line;
	while (1)
	{
		std::cout << "Harl>";
		if (!getline(std::cin, read_line))
		{
			if (std::cin.eof())
				std::cout << std::endl;
			return 0;
		}
		h.complain(read_line);
	}
	return 0;
}