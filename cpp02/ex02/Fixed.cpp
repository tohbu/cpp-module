#include "Fixed.hpp"


Fixed::Fixed() :_integer(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) :_integer(f._integer)
{
	//std::cout << "Copy constructor called" <<std::endl;
}
Fixed::Fixed(const int integer): _integer(integer<<_bit)
{
	std::cout << "Int constructor called" <<std::endl;
}
Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" <<std::endl;
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
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f) 
	{
        this->_integer = f._integer;
    }
    return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" <<std::endl;
}
int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" <<std::endl;
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


bool Fixed::operator>(const Fixed& f)const
{
	return this->_integer > f._integer;
}
bool Fixed::operator<(const Fixed& f)const 
{
	return this->_integer < f._integer;
}
bool Fixed::operator>=(const Fixed& f)const 
{
	return this->_integer >= f._integer;
}
bool Fixed::operator<=(const Fixed& f)const 
{
	return this->_integer <= f._integer;
}
bool Fixed::operator==(const Fixed& f)const 
{
	return this->_integer == f._integer;
}
bool Fixed::operator!=(const Fixed& f)const 
{
	return this->_integer != f._integer;
}

Fixed Fixed:: operator+(const Fixed& a)const
{
	Fixed result;
	result.setRawBits(this->_integer + a.getRawBits());
	return result;
}

Fixed Fixed:: operator-(const Fixed& a)const
{
	Fixed result;
	result.setRawBits(this->_integer - a.getRawBits());
	return result;
}
Fixed Fixed:: operator*(const Fixed& a)const
{
	Fixed result;
	result.setRawBits((this->_integer * a.getRawBits())>>_bit);
	return result;	
}

Fixed Fixed:: operator/(const Fixed& a)const
{
	Fixed result;
	if(a.getRawBits()==0)
	{
		std::cout << "Do not  a division by 0" <<std::endl;
		return result;
	}
	long long n = static_cast<long long>(this->_integer) << _bit;
	long long m = static_cast<long long>(a.getRawBits());
	long long q = n/m;
	result.setRawBits(static_cast<int>(q));
	return result;	
}

Fixed& Fixed:: operator++()
{
	_integer++;
	return *this;
}
Fixed& Fixed:: operator--()
{
	_integer--;
	return *this;
}
Fixed  Fixed:: operator++(int)
{
	Fixed temp(*this);
	_integer++;
	return temp;
}
Fixed  Fixed:: operator--(int)
{
	Fixed temp(*this);
	_integer--;
	return temp;	
}

Fixed& Fixed:: min(Fixed &a, Fixed& b)
{
	return (a < b ? a : b);
}
const Fixed& Fixed:: min(const Fixed &a, const Fixed& b)
{
	return (a < b ? a : b);
}
Fixed& Fixed:: max( Fixed &a,  Fixed& b)
{
	return (a > b ? a : b);
}
const Fixed& Fixed:: max(const Fixed &a, const Fixed& b)
{
	return (a > b ? a : b);
}
std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
