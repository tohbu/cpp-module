#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
	_isguard = false;
	pMsg("Default constructor called <ScavTrap>");
}

ScavTrap::~ScavTrap()
{
	pMsg("Destructor called <ScavTrap>");
}
ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name)
{
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
	_isguard = false;
	pMsg("Name constructor called  <ScavTrap>");
}
ScavTrap &ScavTrap::operator=(const ScavTrap &s)
{
	if (this != &s)
	{
		ClapTrap::operator=(s);
		this->_isguard = s._isguard;
	}
	pMsg("Copy assignment operator called <ScavTrap>");
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (_HitPoint <= 0)
	{
		std::cout << "ScavTrap <" << _name << "> has no hit points left!" << std::endl;
		return;
	}
	if (_EnergyPoint <= 0)
	{
		std::cout << "ScavTrap <" << _name << "> has no energy points left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap <" << _name << "> ";
	std::cout << "attacks"
			  << " <" << target << ">, ";
	std::cout << "causing"
			  << " <" << _AttackDamage << "> "
			  << "points of damage!" << std::endl;
	_EnergyPoint--;
}
void ScavTrap::guardGate()
{
	_isguard = true;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
