#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <math.h>

RobotomyRequestForm::RobotomyRequestForm(/* args */) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() <= getGradeToExecute())
	{
		std::cout << "* drilling noises *" << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Failed to robotomize " << _target << "." << std::endl;
	}
	else
		throw AForm::GradeTooHighException();
}
