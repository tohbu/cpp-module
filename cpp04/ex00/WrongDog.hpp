#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog();
	WrongDog(const std::string &type);
	~WrongDog();
	WrongDog(const WrongDog &d);
	WrongDog &operator=(const WrongDog &d);
	void makeSound() const;
};
#endif
