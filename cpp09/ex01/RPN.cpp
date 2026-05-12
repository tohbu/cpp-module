#include "RPN.hpp"
#include <stdexcept>
#include <cctype>
#include <string>
#include <iostream>
#include <stack>

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
	for (size_t i = 0; i < str.length(); ++i)
	{
		char c = str[i];
		if (c == ' ')
			continue;
		else if (std::isdigit(c))  // number
			_stack.push(c - '0');
		else  // operator
		{
			if (_stack.size() < 2)
			{
				throw std::runtime_error("Invalid RPN expression");
			}
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result = 0;
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
					std::string error_msg = std::string(1, c) + " Invalid operator in RPN expression";
					throw std::runtime_error(error_msg);
			};
			_stack.push(result);
		}
	}
	if (_stack.size() != 1)
	{
		throw std::runtime_error("Invalid RPN expression ");
	}
	return _stack.top();
}