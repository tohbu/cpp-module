#include "Fixed.hpp"


Fixed::Fixed() :_integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) :_integer(f._integer)
{
	std::cout << "Copy constructor called" <<std::endl;
}
Fixed::Fixed(const int integer): _integer(integer<<_bit)
{
	std::cout << "Int constructor called" <<std::endl;
}
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" <<std::endl;
	float result; 
	
	result = f*(1<<_bit);
	if(result >= 0.0f)
		result +=0.5f;
	else
		result -=0.5f;
	_integer = result;
}


Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f) 
	{
        this->_integer = f._integer;
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

float Fixed::toFloat(void)const
{
	return static_cast<float>(_integer)/static_cast<float>(1 <<_bit);
}

int Fixed::toInt(void) const
{
	return _integer>>_bit;
}


std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
