#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <iostream>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(/* args */);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const &executor) const;
};
#endif