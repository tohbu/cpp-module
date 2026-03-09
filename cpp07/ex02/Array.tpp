#include <stdexcept>
#include <cstdlib>
template < typename T >

Array< T >::Array() : _array(NULL), _size(0)
{
}

template < typename T >
Array< T >::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template < typename T >

Array< T >::Array(const Array &other) : _array(new T[other.size()]), _size(other.size())
{
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_array[i] = other._array[i];
	}
}

template < typename T >

Array< T >::~Array()
{
	delete[] this->_array;
}

template < typename T >

Array< T > &Array< T >::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other.size();
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_array[i] = other._array[i];
		}
	}
	return *this;
}

template < typename T >

T &Array< T >::operator[](unsigned int index)
{
	if (index >= this->size())
	{
		throw std::out_of_range("Index out of bounds");
	}
	return this->_array[index];
}

template < typename T >

const T &Array< T >::operator[](unsigned int index) const
{
	if (index >= this->size())
	{
		throw std::out_of_range("Index out of bounds");
	}
	return this->_array[index];
}

template < typename T >

unsigned int Array< T >::size() const
{
	return this->_size;
}