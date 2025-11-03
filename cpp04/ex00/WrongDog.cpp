#include "WrongDog.hpp"

WrongDog:: WrongDog() :WrongAnimal("WrongDog")
{
	std::cout << "WrongDog default constructor called" <<std::endl;
}

WrongDog :: WrongDog(const std::string &type) :WrongAnimal(type)
{
	std::cout << "WrongDog name constructor called" <<std::endl;

}

WrongDog::WrongDog(const WrongDog &d) : WrongAnimal(d._type)
{
	std::cout << "WrongDog copy constructor called" <<std::endl;
}

WrongDog ::~WrongDog()
{
	std::cout << "WrongDog destructor called" <<std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& d)
{
	WrongAnimal::operator=(d);
	return *this;
}

void WrongDog:: makeSound()const
{
	std::cout << "WrongDog Sound" << std::endl;
}
