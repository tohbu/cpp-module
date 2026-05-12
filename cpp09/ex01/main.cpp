#include "RPN.hpp"
#include <iostream>

// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42 
//$ >./ RPN "7 7 * 7 -" 
// 42
//  $ >./ RPN "1 2 * 2 / 2 * 2 4 - +" 
//  0
//   $ >./ RPN "(1 + 1)" 
// Error $ >




	int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}
	RPN rpn;
	try
	{
		int result = rpn.calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
