#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
class RPN
{
public:
	RPN();
	~RPN();
	int calculate(const std::string &expression);

private:
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
};

#endif
