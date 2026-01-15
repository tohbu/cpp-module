#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
class ICharacter;

class Cure : public AMateria
{
protected:
	std::string _type;

public:
	Cure();
	Cure(std::string const &type);
	Cure(const Cure &copy);
	~Cure();
	Cure &operator=(const Cure &other);
	std::string const &getType() const;
	virtual Cure *clone() const;
	virtual void use(ICharacter &target);
};

#endif
