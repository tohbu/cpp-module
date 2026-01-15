#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string &name) :
	_name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << _name << "do not have weapon" << std::endl;
	else
		std::cout << _name << "attacks with their" << _weapon->getType()
				  << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}