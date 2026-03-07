#include "Data.hpp"

Data::Data() : _value(0)
{
}

Data::Data(int value) : _value(value)
{
}

Data::Data(const Data &src) : _value(src._value)
{
}

Data &Data::operator=(const Data &src)
{
	if (this != &src)
		_value = src._value;
	return *this;
}

Data::~Data()
{
}