#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
Base::~Base()
{
}

Base *Base::generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}
void Base::identify(Base *p)
{
	if (dynamic_cast< A * >(p))
		std::cout << "identify pointer to class a" << std::endl;
	else if (dynamic_cast< B * >(p))
		std::cout << "identify pointer to class b" << std::endl;
	else if (dynamic_cast< C * >(p))
		std::cout << "identify pointer to class c" << std::endl;
	return;
}

void Base::identify(Base &p)
{
	try
	{
		dynamic_cast< A & >(p);
		std::cout << "identify reference to class a" << std::endl;
		return;
		/* code */
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast< B & >(p);
		std::cout << "identify reference to class b" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast< C & >(p);
		std::cout << "identify reference to class c" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
}
