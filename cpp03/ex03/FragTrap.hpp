#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
	//
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap& operator=(const FragTrap &f);
		void highFivesGuys(void);


};

#endif
