#include "Cure.hpp"

Cure::Cure() :
	AMateria("cure")
{
}
Cure::Cure(std::string const &type) :
	AMateria(type)
{
}
Cure::Cure(const Cure &copy) :
	AMateria(copy._type)
{
}
Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

std::string const &Cure::getType() const
{
	return _type;
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}