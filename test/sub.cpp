#include <string>

template < typename T >
T add(T a, T b)
{
	return a + b;
}

void f()
{
	add(std::string("hello"), std::string("world"));
	add(6.5, 3.2);
	add(4, 2);
}