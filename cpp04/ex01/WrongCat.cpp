#include "WrongCat.hpp"

WrongCat:: WrongCat() :WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" <<std::endl;
}

WrongCat :: WrongCat(const std::string &type) :WrongAnimal(type)
{
	std::cout << "WrongCat name constructor called" <<std::endl;

}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal(c._type)
{
	std::cout << "WrongCat copy constructor called" <<std::endl;
}

WrongCat ::~WrongCat()
{
	std::cout << "WrongCat destructor called" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& c)
{
	WrongAnimal::operator=(c);
	return *this;
}

void WrongCat:: makeSound()const
{
	std::cout << "WrongCat Sound" << std::endl;
}
