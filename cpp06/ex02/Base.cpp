#include "Base.hpp"
#include <iostream>
Base::~Base()
{
}

Base *Base::generate(void)
{
}

void Base::identify(Base *p)
{
	if (dynamic_cast< A * >(p))
		std::cout << "class a"
}

void Base::identify(Base &p)
{
}