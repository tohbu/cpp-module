#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
class Span
{
private:
	unsigned int _size;
	std::vector< int > _numbers;
	Span();

public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);
	template < typename T >
	void addNumber(T& container, typename T::iterator begin, typename T::iterator end);
	void addNumber();
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};
#endif