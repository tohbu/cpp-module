#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- 1. Normal Test ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		std::cout << "[Action] Pre-incrementing (++bob)..." << std::endl;
		++bob;
		std::cout << "Result: " << bob << std::endl;

		std::cout << "[Action] Post-decrementing (bob--)..." << std::endl;
		bob--;
		std::cout << "Result: " << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- 2. High Grade Exception (Constructor) ---" << std::endl;
	try
	{
		std::cout << "[Action] Creating Bureaucrat with grade 0..." << std::endl;
		Bureaucrat high("TooHigh", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 3. Low Grade Exception (Constructor) ---" << std::endl;
	try
	{
		std::cout << "[Action] Creating Bureaucrat with grade 151..." << std::endl;
		Bureaucrat low("TooLow", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 4.1 GradeTooHigh Increment Test (Post) ---" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		std::cout << "[Action] Post-incrementing (alice++)..." << std::endl;
		alice++;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 4.2 GradeTooHigh Increment Test (Pre) ---" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		std::cout << "[Action] Pre-incrementing (++alice)..." << std::endl;
		++alice;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 5.1 GradeTooLow Decrement Test (Post) ---" << std::endl;
	try
	{
		Bureaucrat james("James", 150);
		std::cout << james << std::endl;
		std::cout << "[Action] Post-decrementing (james--)..." << std::endl;
		james--;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 5.2 GradeTooLow Decrement Test (Pre) ---" << std::endl;
	try
	{
		Bureaucrat james("James", 150);
		std::cout << james << std::endl;
		std::cout << "[Action] Pre-decrementing (--james)..." << std::endl;
		--james;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	return 0;
}