#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm(/* args */);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const &executor) const;
};
#endif
