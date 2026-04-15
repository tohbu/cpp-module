#include "Span.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

Span::Span(unsigned int n) : _size(n)
{
}

Span::Span(const Span &other) : _size(other._size), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _size)
		throw std::out_of_range("Span is full");
	_numbers.push_back(number);
}

template < typename T >
void addNumber(T &container, typename T::iterator begin, typename T::iterator end)
{
	_numbers.insert(_numbers.end(), begin, end);
	if (_numbers.size() >= _size)
		std::out_of_range("Span is full")
}
unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector< int > sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	unsigned int minSpan = std::numeric_limits< unsigned int >::max();
	for (std::vector< int >::iterator i = sortedNumbers.begin() + 1; i != sortedNumbers.end(); ++i)
	{
		unsigned int span = static_cast< unsigned int >(std::abs((static_cast< long long >(*i) - (static_cast< long long >(*(i - 1))))));
		minSpan = std::min(minSpan, span);
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return static_cast< unsigned int >(max - min);
}