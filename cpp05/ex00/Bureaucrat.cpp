#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if(_grade < 1)
		throw std::out_of_range("Grade too high");
	if(_grade > 150)
		throw std::out_of_range("Grade too low");
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
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
		throw std::out_of_range("Grade too high");
	return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
	_grade++;
	if (_grade > 150)
		throw std::out_of_range("Grade too low");
	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	(void)int();
	Bureaucrat temp = *this;
	_grade--;
	if (_grade < 1)
		throw std::out_of_range("Grade too high");
	return temp;
}

Bureaucrat Bureaucrat::operator--(int)
{
	(void)int();
	Bureaucrat temp = *this;
	_grade++;
	if (_grade > 150)
		throw std::out_of_range("Grade too low");
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat _grade " << bureaucrat.getGrade();
	return os;
}
