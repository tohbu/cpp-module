#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Test case 1: Valid Bureaucrat and AForm
	std::cout << "Valid Bureaucrat and AForm----------------------------------------\n"
			  << std::endl;
	Bureaucrat bur("Alice", 1);
	AForm *form = new ShrubberyCreationForm("Garden");
	AForm *form2 = new RobotomyRequestForm("Bob");
	AForm *form3 = new PresidentialPardonForm("Charlie");
	bur.signForm(*form);
	bur.executeForm(*form);

	bur.signForm(*form2);
	bur.executeForm(*form2);

	bur.signForm(*form3);
	bur.executeForm(*form3);
	std::cout << "\nSign miss----------------------------------------\n"
			  << std::endl;
	// Test case 2: Bureaucrat with insufficient grade
	Bureaucrat lowGradeBur("A", 150);
	AForm *Sform = new ShrubberyCreationForm("Park");
	AForm *Rform = new RobotomyRequestForm("Dave");
	AForm *Pform = new PresidentialPardonForm("Eve");
	lowGradeBur.signForm(*form);
	lowGradeBur.executeForm(*form);
	lowGradeBur.signForm(*Sform);
	lowGradeBur.executeForm(*Sform);
	lowGradeBur.signForm(*Rform);
	lowGradeBur.executeForm(*Rform);
	lowGradeBur.signForm(*Pform);
	lowGradeBur.executeForm(*Pform);
	delete Sform;
	delete Rform;
	delete Pform;
	std::cout << "\nExecution attempts with insufficient grade----------------------------------------\n"
			  << std::endl;
	lowGradeBur.executeForm(*form);
	lowGradeBur.executeForm(*form2);
	lowGradeBur.executeForm(*form3);
	std::cout << "----------------------------------------" << std::endl;
	delete form;
	delete form2;
	delete form3;
	return 0;
}
