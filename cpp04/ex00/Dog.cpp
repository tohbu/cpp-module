#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog ::Dog(const std::string &type) :
	Animal(type)
{
	std::cout << "Dog name constructor called" << std::endl;
}

Dog::Dog(const Dog &d) :
	Animal(d._type)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog ::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &d)
{
	Animal::operator=(d);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog Sound" << std::endl;
}
