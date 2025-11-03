#include "Zombie.hpp"
#include<iostream>

Zombie::Zombie() 
{
 	_name = "";	
}
	
Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": died\n";
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
void Zombie::setName(const std::string& name)
{
	_name = name;
}