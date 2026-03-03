#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() <= getGradeToExecute())
	{
		std::string file_name = _target + "_shrubbery";
		std::ofstream out(file_name.c_str());
		if (out.fail())
		{
			std::cerr << "Failed to create file: " << file_name << std::endl;
			return;
		}
		out << "       _-_" << std::endl;
		out << "    /~~   ~~\\" << std::endl;
		out << " /~~         ~~\\" << std::endl;
		out << "{               }" << std::endl;
		out << " \\  _-     -_  /" << std::endl;
		out << "   ~  \\\\ //  ~" << std::endl;
		out << "_- -   | | _- _" << std::endl;
		out << "  _ -  | |   -_" << std::endl;
		out << "      // \\\\" << std::endl;
		out.close();
	}
	else
		throw AForm::GradeTooHighException();
}
