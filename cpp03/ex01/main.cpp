#include"ScavTrap.hpp"

int main(void)
{
	ScavTrap a("tokyo");

	a.attack("kyoto");
	a.attack("kyoto");
	a.takeDamage(5);
	a.beRepaired(3);
	a.takeDamage(20);
	a.attack("Kyoto");
	a.guardGate();
}