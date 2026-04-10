#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int _size;
	std::vector< int > _numbers;
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif