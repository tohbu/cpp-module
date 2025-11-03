#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;		
	public:
		HumanA(const std::string& _name, Weapon& weapon);
		~HumanA();
		void attack(void);
};

#endif