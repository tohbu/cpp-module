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
	int i = rand() % 3 + 1;
	switch (i)
	{
		case 1:
			return new A;
		case 2:
			return new B;
		case 3:
			return new C;
		default:
			return NULL;
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
		(void)dynamic_cast< A & >(p);
		std::cout << "identify reference to class a" << std::endl;
		return;
		/* code */
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		(void)dynamic_cast< B & >(p);
		std::cout << "identify reference to class b" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		(void)dynamic_cast< C & >(p);
		std::cout << "identify reference to class c" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
