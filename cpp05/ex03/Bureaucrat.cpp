#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	std::cout << *this << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	std::cout << *this << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat &Bureaucrat::operator++()
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
	return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	(void)int();
	Bureaucrat temp = *this;
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
	return temp;
}

Bureaucrat Bureaucrat::operator--(int)
{
	(void)int();
	Bureaucrat temp = *this;
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException();
	return temp;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat ::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
				  << " because " << e.what()
				  << ". (Bureaucrat grade: " << this->getGrade() << ")"
				  << std::endl;
	}
}

void Bureaucrat ::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat _grade " << bureaucrat.getGrade();
	return os;
}
