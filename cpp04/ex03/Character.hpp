#ifndef	CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include<iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#define  FLOOR_MATE 40

 class Character : public ICharacter
 {
	private:
		std::string _name;
		AMateria *_material[4];
		AMateria *_floor[FLOOR_MATE];
	public:
		Character();
		Character(std::string name);
		Character(const Character& copy);
		Character& operator=(const Character& ch);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m) ;
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
 };

#endif