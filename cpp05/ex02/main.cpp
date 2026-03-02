#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << "--- 1. Normal Test ---" << std::endl;
	Bureaucrat bob("Bob", 2);
	AForm taxForm("TaxForm", 1, 1);
	AForm tax2Form("Tax2Form", 2, 2);
	AForm tax3Form("Tax3Form", 3, 3);
	std::cout << taxForm << tax2Form << tax3Form << std::endl;
	bob.signForm(taxForm);
	bob.signForm(tax2Form);
	bob.signForm(tax3Form);
	try
	{
		AForm invalidForm("InvalidForm", 0, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm invalidForm("InvalidForm", 1, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm invalidForm("InvalidForm", 151, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm invalidForm2("InvalidForm2", 1, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}