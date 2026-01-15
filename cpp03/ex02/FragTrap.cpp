#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap()
{
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	pMsg("Default constructor called <FragTrap>");
}
FragTrap::~FragTrap()
{
	pMsg("Destructor called <FragTrap>");
}
FragTrap::FragTrap(std::string name) :
	ClapTrap(name)
{
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	pMsg("Name constructor called  <FragTrap>");
}
FragTrap &FragTrap::operator=(const FragTrap &f)
{
	ClapTrap::operator=(f);
	pMsg("Copy assignment operator called <FragTrap>");
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}
