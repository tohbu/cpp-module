#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
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
	template < typename T, typename It >
	void addNumber(const T &container, It begin, It end)
	{
		if (container.begin() != begin || container.end() != end)
			throw std::invalid_argument("Invalid range iterators");
		if (_numbers.size() + std::distance(begin, end) > _size)
			throw std::out_of_range("Span is full");
		_numbers.insert(_numbers.end(), begin, end);
	}
	void addNumber();
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};
#endif