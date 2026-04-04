#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

enum LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_LITERAL,
	UNKNOWN
};

class ScalarConverter
{
public:
	static void convert(const std::string &literal);
};

std::ostream &operator<<(std::ostream &os, LiteralType type);

#endif
