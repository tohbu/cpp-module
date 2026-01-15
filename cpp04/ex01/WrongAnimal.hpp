#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &a);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &a);
	void makeSound() const;
	void setType(std::string type);
	std::string getType(void) const;
};
#endif