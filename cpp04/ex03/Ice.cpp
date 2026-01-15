#include "Ice.hpp"

Ice::Ice() :
	AMateria("ice")
{
}
Ice::Ice(std::string const &type) :
	AMateria(type)
{
}
Ice::Ice(const Ice &copy) :
	AMateria(copy._type)
{
}
Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &ic)
{
	if (this != &ic)
		AMateria::operator=(ic);
	return *this;
}

std::string const &Ice::getType() const
{
	return _type;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}