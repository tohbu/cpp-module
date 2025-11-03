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
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);
		~Fixed();
		int getRawBits(void)const;
		void setRawBits(int const raw);
};




#endif