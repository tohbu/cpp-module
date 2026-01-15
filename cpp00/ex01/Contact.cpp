#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Contact::Contact()
{
}

std::string print_format(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	else
		return s;
}

bool read_required_line(const char *prompt, std::string &out)
{
	while (1)
	{
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, out))
			throw std::runtime_error("EOF");
		if (!out.empty())
			return true;
	}
}

void Contact::print(int index)
{
	std::cout << std::setw(10) << std::right << "index"
			  << "|";
	std::cout << std::setw(10) << std::right << "first_name"
			  << "|";
	std::cout << std::setw(10) << std::right << "last_name"
			  << "|";
	std::cout << std::setw(10) << std::right << "nick_name"
			  << "|";
	std::cout << std::endl;
	//
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << print_format(_first_name)
			  << "|";
	std::cout << std::setw(10) << std::right << print_format(_last_name) << "|";
	std::cout << std::setw(10) << std::right << print_format(_nick_name) << "|";
	std::cout << std::endl;
}
void Contact::print_all()
{
	std::cout << "first_name: " << _first_name << std::endl;
	std::cout << "last_name: " << _last_name << std::endl;
	std::cout << "nick_name: " << _nick_name << std::endl;
	std::cout << "phone_number: " << _phone_number << std::endl;
	std::cout << "darkest: " << _darkest << std::endl;
}
void Contact::read_input(void)
{
	read_required_line("first_name>", _first_name);
	read_required_line("last_name>", _last_name);
	read_required_line("nick_name>", _nick_name);
	read_required_line("phone_number>", _phone_number);
	read_required_line("darkest>", _darkest);
}
