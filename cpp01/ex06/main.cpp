#include "Harl.hpp"
#include<iostream>
#include<string>

int main(int argc, char*argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		std::cout << "Example: ./harlFilter WARNING" << std::endl;
		return 1; 
	}
	Harl h;
	h.complain(argv[1]);
	return 0;
}