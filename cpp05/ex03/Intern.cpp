#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(/* args */)
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}
Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formname, const std::string &target)
{
	
	std::string formnames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int key = -1;
	for (int i = 0; i < 3; i++)
	{
		if (formname == formnames[i])
		{
			key = i;
			break;
		}
	}
	switch (key)
	{
		case 0:
			std::cout << "Intern creates " << formnames[0] << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << formnames[1] << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << formnames[2] << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern can't create " << formname << std::endl;
			return (NULL);
	}
}
