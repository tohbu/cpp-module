#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(/* args */);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const &executor) const;
};
#endif
