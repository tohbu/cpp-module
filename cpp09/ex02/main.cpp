#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
bool isValidateInput(int argc, char *argv[])
{
	std::vector< int > vect;
	for (int i = 1; i < argc; ++i)
	{
		std::string str(argv[i]);
		if (str.empty())
			return false;
		for (size_t j = 0; j < str.size(); ++j)
		{
			if (!std::isdigit(str[j]))
			{
				std::cerr << "Error: Invalid input '" << str << "'. Only positive integers are allowed." << std::endl;
				return false;
			}
		}
		if (std::find(vect.begin(), vect.end(), std::atoi(str.c_str())) != vect.end())
		{
			std::cerr << "Error: Duplicate number found: " << str << std::endl;
			return false;
		}
		vect.push_back(std::atoi(str.c_str()));
	}
	return true;
}

//test case
// ./ PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

#include "PmergeMe.hpp"
#include <list>
#include <vector>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
		return 1;
	}
	if (!isValidateInput(argc, argv))
		return 1;
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << " (" << argc - 1 << " elements)" << std::endl;
	PmergeMe< std::vector< int > > pm(argc, argv, std::vector< int >(), "vector");
	PmergeMe< std::list< int > > pm2(argc, argv, std::list< int >(), "list");
	std::cout << "After: ";
	pm.printContainer(argc);
	pm.printResults();
	pm2.printResults();
	return 0;
}
