#include "Base.hpp"
#include <iostream>
int main()
{
	int count = 5;
	for (int i = 0; i < count; i++)
	{
		/* code */
		std::cout << "------------------" << std::endl;
		Base *base = Base::generate();
		Base::identify(base);
		Base::identify(*base);
		delete base;
		std::cout << "------------------" << std::endl;
	}
}
