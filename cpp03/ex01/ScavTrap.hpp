#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap :public ClapTrap
{
	private:
		bool _isguard;
		/* data */
	public:
		ScavTrap(/* args */);
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap& s);
		void guardGate();
		void attack(const std::string& target);
};


#endif