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
	BitcoinExchange btc(argv[1]);
}
