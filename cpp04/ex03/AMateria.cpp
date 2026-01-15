#include "AMateria.hpp"

AMateria::AMateria() :
	_type()
{
}
AMateria::AMateria(std::string const &type) :
	_type(type)
{
}
AMateria::AMateria(const AMateria &copy) :
	_type(copy._type)
{
}
AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &am)
{
	if (this != &am)
	{
		this->_type = am.getType();
	}
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "use" << _type << "to" << target.getName() << std::endl;
}