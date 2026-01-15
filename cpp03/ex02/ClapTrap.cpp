#include "ClapTrap.hpp"

void pMsg(const std::string &msg)
{
	std::cout << msg << std::endl;
}

ClapTrap::ClapTrap() :
	_name(), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	pMsg("Default constructor called <ClapTrap>");
}
ClapTrap::ClapTrap(std::string name) :
	_name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	pMsg("Name constructor called  <ClapTrap>");
}

ClapTrap::ClapTrap(const ClapTrap &c) :
	_name(c._name), _HitPoint(c._HitPoint), _EnergyPoint(c._EnergyPoint), _AttackDamage(c._AttackDamage)
{
	pMsg("Copy constructor called  <ClapTrap>");
}

ClapTrap::~ClapTrap()
{
	pMsg("Destructor called <ClapTrap>");
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	if (this != &c)
	{
		this->_name = c._name;
		this->_AttackDamage = c._AttackDamage;
		this->_EnergyPoint = c._EnergyPoint;
		this->_HitPoint = c._HitPoint;
	}
	pMsg("Copy assignment operator called <ClapTrap>");
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_HitPoint <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> has no hit points left!" << std::endl;
		return;
	}
	if (_EnergyPoint <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> has no energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap <" << _name << "> ";
	std::cout << "attacks"
			  << " <" << target << ">, ";
	std::cout << "causing"
			  << " <" << _AttackDamage << "> "
			  << "points of damage!" << std::endl;
	_EnergyPoint--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap "
			  << "<" << _name << "> ";
	std::cout << "take damage "
			  << "<" << amount << ">" << std::endl;
	_HitPoint -= amount;
	if (_HitPoint <= 0)
		std::cout << "ClapTrap "
				  << "<" << _name << "> "
				  << "game over" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoint <= 0)
	{
		std::cout << "ClapTrap <" << _name << "> has no hit points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap "
			  << "<" << _name << "> ";
	std::cout << "repairs "
			  << "<" << amount << ">" << std::endl;
	_EnergyPoint--;
	_HitPoint += amount;
}