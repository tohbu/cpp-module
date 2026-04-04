#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <limits>

const std::string important_literals[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};

//int  INT_MAXのとき　CHARはどうなるのか？
//int max >

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return *this;
}

ScalarConverter::LiteralType detect_type(const std::string &literal)
{
	for (int i = 0; i < 6; ++i)
	{
		if (literal == important_literals[i])
			return ScalarConverter::PSEUDO_LITERAL;
	}
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return ScalarConverter::CHAR;
	std::istringstream iss(literal);
	long int int_val;
	if (iss >> int_val && iss.eof())
	{
		if (std::numeric_limits< int >::min() <= int_val && int_val <= std::numeric_limits< int >::max())
			return ScalarConverter::INT;
		else
			return ScalarConverter::DOUBLE;
	}
	std::istringstream iss_double(literal);
	double double_val;
	if (iss_double >> double_val)
	{
		if (iss_double.eof())
			return ScalarConverter::DOUBLE;
		char last_char;
		iss_double >> last_char;
		if (last_char == 'f' && iss_double.eof())
			return ScalarConverter::FLOAT;
	}
	return ScalarConverter::UNKNOWN;
}

void print_result(char char_output, int int_output, float float_output, double double_output)
{
	std::cout << "char: ";

	//char
	double char_min = static_cast< int >(std::numeric_limits< char >::min());
	double char_max = static_cast< int >(std::numeric_limits< char >::max());

	if (!(char_min <= int_output && int_output <= char_max))
		std::cout << "impossible";
	else if (std::isprint(char_output))
		std::cout << "'" << char_output << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	//int
	double int_min = static_cast< double >(std::numeric_limits< int >::min());
	double int_max = static_cast< double >(std::numeric_limits< int >::max());

	if (!(int_min <= double_output && double_output <= int_max))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int_output << std::endl;
	//float
	if (float_output - static_cast< int >(float_output) == 0)
		std::cout << "float: " << float_output << ".0f" << std::endl;
	else
		std::cout << "float: " << float_output << "f" << std::endl;
	//double
	if (double_output - static_cast< int >(double_output) == 0)
		std::cout << "double: " << double_output << ".0" << std::endl;
	else
		std::cout << "double: " << double_output << std::endl;
}

void print_result_impossible(float float_output, double double_output)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (float_output == std::numeric_limits< float >::infinity())
		std::cout << "float: +" << float_output << "f" << std::endl;
	else
		std::cout << "float: " << float_output << "f" << std::endl;
	if (double_output == std::numeric_limits< double >::infinity())
		std::cout << "double: +" << double_output << std::endl;
	else
		std::cout << "double: " << double_output << std::endl;
}
//型の特定の後、それぞれの型に対して変換関数を呼び出すような実装
void ScalarConverter::convert(const std::string &literal)
{
	LiteralType type = detect_type(literal);

	char char_output;
	int int_output;
	float float_output;
	double double_output;
	std::cout << "Detected type: " << type << std::endl;
	switch (type)
	{
		case ScalarConverter::CHAR:
		{
			char_output = literal[0];
			int_output = static_cast< int >(char_output);
			float_output = static_cast< float >(char_output);
			double_output = static_cast< double >(char_output);
			break;
		}
		case ScalarConverter::INT:
		{
			int_output = std::atoi(literal.c_str());
			char_output = static_cast< char >(int_output);
			float_output = static_cast< float >(int_output);
			double_output = static_cast< double >(int_output);
			break;
		}
		case ScalarConverter::FLOAT:
		{
			float_output = std::atof(literal.c_str());
			char_output = static_cast< char >(float_output);
			int_output = static_cast< int >(float_output);
			double_output = static_cast< double >(float_output);
			break;
		}
		case ScalarConverter::DOUBLE:
		{
			double_output = std::atof(literal.c_str());
			char_output = static_cast< char >(double_output);
			int_output = static_cast< int >(double_output);
			float_output = static_cast< float >(double_output);
			break;
		}
		case ScalarConverter::PSEUDO_LITERAL:
		{
			float_output = 0.0f;
			double_output = 0.0;
			if (literal == "nan" || literal == "nanf")
			{
				float_output = std::numeric_limits< float >::quiet_NaN();
				double_output = std::numeric_limits< double >::quiet_NaN();
			}
			else if (literal == "+inf" || literal == "+inff")
			{
				float_output = std::numeric_limits< float >::infinity();
				double_output = std::numeric_limits< double >::infinity();
			}
			else if (literal == "-inf" || literal == "-inff")
			{
				float_output = -std::numeric_limits< float >::infinity();
				double_output = -std::numeric_limits< double >::infinity();
			}
			print_result_impossible(float_output, double_output);
			return;
		}
		default:
			std::cout << "Unknown type" << std::endl;
			return;
	}
	print_result(char_output, int_output, float_output, double_output);
}

std::ostream &operator<<(std::ostream &os, ScalarConverter::LiteralType type)
{
	switch (type)
	{
		case ScalarConverter::CHAR:
			os << "CHAR";
			break;
		case ScalarConverter::INT:
			os << "INT";
			break;
		case ScalarConverter::FLOAT:
			os << "FLOAT";
			break;
		case ScalarConverter::DOUBLE:
			os << "DOUBLE";
			break;
		case ScalarConverter::PSEUDO_LITERAL:
			os << "PSEUDO_LITERAL";
			break;
		default:
			os << "UNKNOWN";
			break;
	}
	return os;
}

// Implementation of the conversion logic goes here.
// This function should parse the input literal and convert it to char, int, float, and double types,
// then print the results in the required format.
