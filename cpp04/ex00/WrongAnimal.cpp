#include "WrongAnimal.hpp"

WrongAnimal:: WrongAnimal() :_type()
{
	std::cout << "WrongAnimal default constructor called" <<std::endl;
}

WrongAnimal :: WrongAnimal(const std::string &type) :_type(type)
{
	std::cout << "WrongAnimal name constructor called" <<std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &a) : _type(a._type)
{
	std::cout << "WrongAnimal copy constructor called" <<std::endl;
}

WrongAnimal ::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" <<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	if(this != &a)
	{
		this->setType(a.getType());
	}
	return *this;
}

void WrongAnimal:: makeSound()const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

void WrongAnimal:: setType(std::string type)
{
	this->_type = type;
}

std::string WrongAnimal::getType(void)const
{
	return _type;
}