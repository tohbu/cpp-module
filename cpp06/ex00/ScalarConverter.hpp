#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
public:
	enum LiteralType
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO_LITERAL,
		UNKNOWN
	};

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &rhs);

public:
	static void convert(const std::string &literal);
};

std::ostream &operator<<(std::ostream &os, ScalarConverter::LiteralType type);

#endif
