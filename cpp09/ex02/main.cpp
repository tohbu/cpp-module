#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
		return 1;
	}
	try
	{
		// std::cout << "Input: " << argc - 1 << std::endl;
		// std::cout << "Before: ";
		// for (int i = 1; i < argc; ++i)
		// {
		// 	std::cout << argv[i] << " ";
		// }
		std::cout << std::endl;
		PmergeMe pmergeMe(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}