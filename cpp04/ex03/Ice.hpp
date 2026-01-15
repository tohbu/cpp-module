#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
class ICharacter;

class Ice : public AMateria
{
protected:
	std::string _type;

public:
	Ice();
	Ice(std::string const &type);
	Ice(const Ice &copy);
	~Ice();
	Ice &operator=(const Ice &other);

	std::string const &getType() const;
	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
};

#endif