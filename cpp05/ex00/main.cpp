#include "Bureaucrat.hpp"
#include <iostream>
int main()
{
	try
	{
		Bureaucrat b(std::string("Alice"),2);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat b(std::string("Bob"),151);
		std::cout << b << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	
	}
	try
	{
		Bureaucrat b(std::string("Charlie"),1);
		std::cout << b << std::endl;
		b++;
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}