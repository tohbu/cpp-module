#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <math.h>

class Fixed
{
private:
	int _integer;
	static const int _bit = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int integer);
	Fixed(const float f);
	Fixed &operator=(const Fixed &f);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);
#endif