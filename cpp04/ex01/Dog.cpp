#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog ::Dog(const std::string &type) :
	Animal(type)
{
	std::cout << "Dog name constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &d) :
	Animal(d._type)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*d._brain);
}

Dog ::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &d)
{
	Animal::operator=(d);
	delete _brain;
	_brain = new Brain(*d._brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog Sound" << std::endl;
}
