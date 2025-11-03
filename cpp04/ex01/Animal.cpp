#include "Animal.hpp"

Animal:: Animal() :_type() 
{
	std::cout << "Animal default constructor called" <<std::endl;
}

Animal :: Animal(const std::string &type) :_type(type)
{
	std::cout << "Animal name constructor called" <<std::endl;	

}

Animal::Animal(const Animal &a) : _type(a._type)
{
	std::cout << "Animal copy constructor called" <<std::endl;
}

Animal ::~Animal()
{
	std::cout << "Animal destructor called" <<std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
	if(this != &a)
	{
		this->setType(a.getType());
	}
	return *this;
}

void Animal:: makeSound()const
{
	std::cout << "Animal Sound" << std::endl;
}

void Animal:: setType(std::string type)
{
	this->_type = type;
}

std::string Animal::getType(void)const
{
	return _type;
}