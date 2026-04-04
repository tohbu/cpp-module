#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
int main()
{
	int count = 5;
	for (int i = 0; i < count; i++)
	{
		/* code */
		sleep(1);
		std::srand(time(NULL));
		std::cout << "------------------" << std::endl;
		Base *base = Base::generate();
		Base::identify(base);
		Base::identify(*base);
		delete base;
		std::cout << "------------------" << std::endl;
	}
}
