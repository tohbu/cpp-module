#include "ShrubberyCreationForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "Notice: PresidentialPardonForm assignment operator called. "
			  << "Attributes like Name and Grades are constant and cannot be overwritten." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}



