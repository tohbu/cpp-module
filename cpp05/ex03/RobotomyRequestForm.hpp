#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <iostream>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm(/* args */);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const &executor) const;
};
#endif
