#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>

const std::string important_literals[6] = {
	"nan", "nanf", "+inf", "-inf", "+inff", "-inff"
};

void convert_char(const std::string& literal)
{
	// Implementation for converting to char and printing the result.
	char output = 0;
	for(size_t i = 0; i < literal.size(); ++i)
	{
		if (!isprint(literal[i]))
		{
			std::cout << "char: Non displayable" << std::endl;
			return;
		}
		if(isdigit(literal[i]))
		{
			char now = static_cast<char>(literal[i]);
			output = output * 10 + (now - '0');
		}
		else
			break;	
	}
	if (output < 0 || output > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	

}

void convert_int(const std::string& literal)
{
	// Implementation for converting to int and printing the result.
}

void convert_float(const std::string& literal)
{
	// Implementation for converting to float and printing the result.
}

void convert_double(const std::string& literal)
{
	// Implementation for converting to double and printing the result.
}



void ScalarConverter::convert(const std:: string& literal)
{
	for(size_t i = 0; i < 6; ++i)
	{
		if (literal == important_literals[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << important_literals[i] << "f" << std::endl;
			std::cout << "double: " << important_literals[i] << std::endl;
			return;
		}
	}
	//char
	convert_char(literal);	
	//int
	convert_int(literal);
	// float
	convert_float(literal);
	// double
	convert_double(literal);
	// Implementation of the conversion logic goes here.
	// This function should parse the input literal and convert it to char, int, float, and double types,
	// then print the results in the required format.
}