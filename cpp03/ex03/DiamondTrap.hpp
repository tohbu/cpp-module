#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap
{
private:
	/* data */
public:
	DiamondTrap(/* args */);
	~DiamondTrap();
};

DiamondTrap::DiamondTrap(/* args */)
{
}

DiamondTrap::~DiamondTrap()
{
}

#endif