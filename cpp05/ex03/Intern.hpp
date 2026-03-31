#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
class Intern
{
private:
	/* data */
public:
	Intern(/* args */);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	AForm *makeForm(const std::string &formname, const std::string &target);
};

#endif
