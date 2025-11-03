#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string &type);
		~WrongCat();
		WrongCat (const WrongCat& c);
		WrongCat& operator=(const WrongCat& c);
		void makeSound()const;
};
#endif


