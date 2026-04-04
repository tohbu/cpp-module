#include <iostream>

template < typename T >
T add(T a, T b);

int main()
{
	std::cout << add(4, 2) << std::endl;
	return 0;
}