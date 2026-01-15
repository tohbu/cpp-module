#include <iostream>
#include <string>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;

	std::cout << "The memory address of the string variable	" << &s << std::endl;
	std::cout << "The memory address held by stringPTR		" << ptr << std::endl;
	std::cout << "The memory address held by stringREF		" << &ref << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "The value of the string variable	" << s << std::endl;
	std::cout << "The value pointed to by stringPTR	" << *ptr << std::endl;
	std::cout << "The value pointed to by stringREF	" << ref << std::endl;
}
