#include "MateriaSource.hpp"
MateriaSource::MateriaSource() :
	_materia_tmp(), idx(0)
{
}
MateriaSource::MateriaSource(const MateriaSource &copy) :
	idx(copy.getIdx())
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia_tmp[i])
			this->_materia_tmp[i] = (*copy._materia_tmp[i]).clone();
		else
			this->_materia_tmp[i] = NULL;
	}
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other._materia_tmp[i])
			{
				if (this->_materia_tmp[i])
					delete this->_materia_tmp[i];
				this->_materia_tmp[i] = (*other._materia_tmp[i]).clone();
			}
			else
			{
				if (this->_materia_tmp[i])
					delete this->_materia_tmp[i];
				this->_materia_tmp[i] = NULL;
			}
		}
	}
	idx = other.getIdx();
	return *this;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia_tmp[i])
			delete _materia_tmp[i];
	}
}
void MateriaSource::learnMateria(AMateria *am)
{
	if (_materia_tmp[idx])
	{
		delete _materia_tmp[idx];
	}
	_materia_tmp[idx % 4] = am;
	std::cout << "learn Mate " << _materia_tmp[idx % 4]->getType() << std::endl;
	idx++;
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia_tmp[i] && _materia_tmp[i]->getType() == type)
		{
			std::cout << "create Mater " << _materia_tmp[i]->getType() << std::endl;
			return _materia_tmp[i]->clone();
		}
	}
	std::cout << "no Materia type" << std::endl;
	return NULL;
}

int MateriaSource::getIdx() const
{
	return idx;
}