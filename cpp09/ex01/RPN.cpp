#include "RPN.hpp"
#include <stdexcept>
#include <cctype>
#include <string>
#include <iostream>
RPN::RPN()
{
}
RPN ::~RPN()
{
}
int RPN::calculate(const std::string &str)
{
	std::stack< int > stack;
	for (size_t i = 0; i < str.length(); ++i)
	{
		char c = str[i];
		if (c == ' ')
			continue;
		else if (std::isdigit(c))  // number
			stack.push(c - '0');
		else  // operator
		{
			if (stack.size() != 2)
			{
				throw std::runtime_error("Invalid RPN expression");
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result;
			switch (c)
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Division by zero");
					result = a / b;
					break;
				default:
					throw std::runtime_error("Invalid operator in RPN expression");
			}
			stack.push(result);
		}
	}
	if (stack.size() != 1)
	{
		throw std::runtime_error("Invalid RPN expression ");
	}
	return stack.top();
}