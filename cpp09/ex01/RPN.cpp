#include "RPN.hpp"
#include <stdexcept>
#include <cctype>
#include <string>
#include <iostream>
#include <stack>
#include <limits>

RPN::RPN()
{
}
RPN ::~RPN()
{
}

RPN ::RPN(const RPN &other) : _stack(other._stack)
{
}
RPN &RPN ::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

int RPN::calculate(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		char s = str[i];
		if (std::isspace(s))
			continue;
		if (std::isdigit(s))  // number
		{
			if (i + 1 < str.size() && std::isdigit(str[i + 1]))	 // 二桁以上
				throw std::runtime_error("Digit must be [1-9] in RPN expression");
			else
				_stack.push(s - '0');
		}
		else  // operator
		{
			if (_stack.size() < 2)
			{
				throw std::runtime_error("Invalid RPN expression");
			}
			long b = _stack.top();
			_stack.pop();
			long a = _stack.top();
			_stack.pop();
			long result = 0;
			switch (s)
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
					std::string error_msg = std::string(1, s) + " Invalid operator in RPN expression";
					throw std::runtime_error(error_msg);
			};
			//std::cout << "Debug: " << a << " " << s << " " << b << " = " << result << std::endl; // Debug output
			if (result < static_cast<long>(std::numeric_limits< int >::min()) || result > static_cast<long>(std::numeric_limits< int >::max()))
				throw std::runtime_error("Result out of int range");
			_stack.push(result);
		}
	}
	if (_stack.size() != 1)
	{
		throw std::runtime_error("Invalid RPN expression ");
	}
	return _stack.top();
}