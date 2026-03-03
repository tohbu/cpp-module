#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(ScalarConverter const & src) = delete;
		~ScalarConverter() = delete;
		ScalarConverter & operator=(ScalarConverter const & rhs) = delete;

		static void convert(const std::string& literal);
};

#endif
