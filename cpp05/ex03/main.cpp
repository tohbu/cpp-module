#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *rrf;
	AForm *scf;
	AForm *ppf;
	scf = someRandomIntern.makeForm("shrubbery creation", "home");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod Beeblebrox");

	delete rrf;
	delete scf;
	delete ppf;

	AForm *wrong = someRandomIntern.makeForm("wrong form", "target");
	delete wrong;
}
