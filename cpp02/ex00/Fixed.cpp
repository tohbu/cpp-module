#include "Fixed.hpp"


Fixed::Fixed() :_integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) :_integer(f._integer)
{
	std::cout << "Copy constructor called" <<std::endl;
}

Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f) 
	{
        this->_integer = f.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return _integer;
}

void Fixed::setRawBits(int const raw)
{
	_integer = raw;
}
