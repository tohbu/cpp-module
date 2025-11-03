#include "Cat.hpp"

Cat:: Cat() :Animal("Cat")
{
	std::cout << "Cat default constructor called" <<std::endl;
	_brain = new Brain();
}

Cat :: Cat(const std::string &type) :Animal(type)
{
	std::cout << "Cat name constructor called" <<std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &c) : Animal(c._type)
{
	std::cout << "Cat copy constructor called" <<std::endl;
	_brain = new Brain(*c._brain);

}

Cat ::~Cat()
{
	std::cout << "Cat destructor called" <<std::endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat& c)
{
	Animal::operator=(c);
	delete _brain;
	_brain = new Brain(*c._brain);	
	return *this;
}

void Cat:: makeSound()const
{
	std::cout << "Cat Sound" << std::endl;
}
