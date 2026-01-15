#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("tokyo");

	a.attack("kyoto");
	a.attack("kyoto");
	a.takeDamage(5);
	a.beRepaired(3);
	a.takeDamage(20);
	a.attack("Kyoto");
	a.highFivesGuys();
}