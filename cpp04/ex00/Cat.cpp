#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat ::Cat(const std::string &type) :
	Animal(type)
{
	std::cout << "Cat name constructor called" << std::endl;
}

Cat::Cat(const Cat &c) :
	Animal(c._type)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat ::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &c)
{
	Animal::operator=(c);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat Sound" << std::endl;
}
