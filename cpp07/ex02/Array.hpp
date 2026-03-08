#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

template < typename T >

class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array() : _array(NULL), _size(0)
	{
	}
	Array(unsigned int n) : _array(new T[n]), _size(n)
	{
	}
	Array(const Array &other) : _array(new T[other.size()]), _size(other.size())
	{
		for (size_t i = 0; i < other.size(); i++)
		{
			this->_array[i] = other._array[i];
		}
	}
	~Array()
	{
		delete[] this->_array;
	}
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] this->_array;
			this->_array = new T[other.size()];
			this->_size = other.size();
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_array[i] = other._array[i];
			}
		}
		return *this;
	}

	T &operator[](unsigned int index)
	{
		if (index >= this->_size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return this->_array[index];
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= this->_size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return const_cast< T & >(this->_array[index]);
	}
	unsigned int size() const
	{
		return this->_size;
	}
};

#endif

// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:
// • Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (al
// locating memory in advance) is forbidden. Your program must never access non
// allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • Amember function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.