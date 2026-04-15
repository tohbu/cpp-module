#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);
	//
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	//
	Span sp2 = Span(10);
	sp2.addNumber(1);
	try
	{
		sp2.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "shortestSpan Error: " << e.what() << std::endl;
	}
	try
	{
		sp2.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "longestSpan Error: " << e.what() << std::endl;
	}
	//
	std::vector< int > vec;
	std::vector< int > vec2;
	for (int i = 0; i < 10000; ++i)
	{
		vec.push_back(i);
		vec2.push_back(i * 2);
	}
	Span sp3 = Span(10000);
	try
	{
		// Invalid range (vec2.end() instead of vec.end())
		sp3.addNumber(vec, vec.begin(), vec2.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	sp3.addNumber(vec, vec.begin(), vec.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	// Attempt to add a number to a full Span
	try
	{
		sp3.addNumber(10000);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp.addNumber(vec2, vec2.begin(), vec2.end());
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}