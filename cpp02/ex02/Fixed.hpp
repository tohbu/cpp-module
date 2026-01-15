#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

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

	bool operator>(const Fixed &f) const;
	bool operator<(const Fixed &f) const;
	bool operator>=(const Fixed &f) const;
	bool operator<=(const Fixed &f) const;
	bool operator==(const Fixed &f) const;
	bool operator!=(const Fixed &f) const;

	Fixed operator+(const Fixed &a) const;
	Fixed operator-(const Fixed &a) const;
	Fixed operator*(const Fixed &a) const;
	Fixed operator/(const Fixed &a) const;

	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);
#endif