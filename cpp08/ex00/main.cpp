#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"
int main()
{
	std::vector< int > vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::list< int > lst;
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	try
	{
		std::vector< int >::iterator it1 = easyfind(vec, 2);		  // Should find the value
		std::list< int >::iterator it2 = easyfind(lst, 5);			  // Should find the value
		std::cout << "Value found in vector: " << *it1 << std::endl;  // Output: Value found in vector: 2
		std::cout << "Value found in list: " << *it2 << std::endl;	  // Output: Value found in list: 5
		std::vector< int >::iterator it3 = easyfind(vec, 10);
		std::cout << "Value found in vector: " << *it3 << std::endl;  // Should throw an exception
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;	 // Output: Value not found in container
	}

	return 0;
}