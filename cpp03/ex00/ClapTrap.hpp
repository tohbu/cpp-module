#ifndef CLAPTRAP_HPP
#define  CLAPTRAP_HPP
#include<string>
#include<iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _HitPoint;
		int _EnergyPoint;
		int _AttackDamage;

		/* data */
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& c);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& c);

		ClapTrap(std::string _name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif
