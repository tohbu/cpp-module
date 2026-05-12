#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
