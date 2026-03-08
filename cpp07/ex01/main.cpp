#include <iostream>
#include <string>
#include "iter.hpp"

template < typename T >
void print(T &a)
{
	std::cout << "Value: " << a << std::endl;
}
template < typename T >

void add(T &a)
{
	a += 1;
	std::cout << "After adding 1: " << a << std::endl;
}

const std::string &printString(const std::string &a)
{
	std::cout << "Value: " << a << std::endl;
	return a;
}
int main()
{
	std::cout << "Testing iter with int array:" << std::endl;
	int array[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(array) / sizeof(array[0]);
	::iter(array, length, print< int >);
	::iter(array, length, add< int >);
	std::cout << "\nTesting iter with double array:" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	::iter(doubleArray, doubleLength, print< double >);
	::iter(doubleArray, doubleLength, add< double >);

	std::cout << "\nTesting iter with string array:" << std::endl;
	std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
	size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);
	::iter(stringArray, stringLength, print< std::string >);

	const int constIntArray[] = {10, 20, 30, 40, 50};
	size_t constIntLength = sizeof(constIntArray) / sizeof(constIntArray[0]);
	std::cout << "\nTesting iter with const int array:" << std::endl;
	::iter(constIntArray, constIntLength, print< const int >);
	::iter(constIntArray, constIntLength, add< int >);

	const std::string constStringArray[] = {"Const", "String", "Array"};
	size_t constStringLength = sizeof(constStringArray) / sizeof(constStringArray[0]);
	std::cout << "\nTesting iter with const string array:" << std::endl;
	::iter(constStringArray, constStringLength, print< const std::string >);
	std::cout << "\nTesting iter with const string array:" << std::endl;
	::iter(constStringArray, constStringLength, printString);
}
