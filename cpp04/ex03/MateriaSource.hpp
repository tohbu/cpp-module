#ifndef	MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <string>
#include<iostream>
#include"IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource 
{
	private:
		AMateria*	_materia_tmp[4];
		int idx;
	public:
		MateriaSource(); 
		MateriaSource(const MateriaSource &copy);
		MateriaSource& operator=(const MateriaSource &other);
		~MateriaSource() ;
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		int getIdx(void)const;
};


#endif