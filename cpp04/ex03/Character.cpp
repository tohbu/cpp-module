#include"Character.hpp"

Character:: Character() :_name(), _material() ,_floor()
{
	std::cout<< "character constructor" <<std::endl;
}

Character:: Character(std::string name) :_name(name), _material() ,_floor()
{
	std::cout<< "character name constructor" <<std::endl;
}

Character:: Character(const Character& copy) :_name(copy._name)
{
	for( int i = 0; i < 4; i++)
	{
		if(copy._material[i] == NULL)
			this->_material[i] = NULL;
		else
		{
			this->_material[i] = (copy._material[i])->clone();
		}
	}
	for(int i =0; i < FLOOR_MATE; i++)
	{
		if(copy._floor[i] == NULL)
			this->_floor[i] = NULL;
		else
		{
			this->_floor[i] = (copy._floor[i])->clone();
		}
	}
	return;
}

Character& Character::operator=(const Character& ch)
{
	if(this != &ch)
	{
		_name = ch.getName();
			for( int i = 0; i < 4; i++)
			{
				if(ch._material[i] == NULL)
					this->_material[i] = NULL;
				else
				{
					delete _material[i];
					this->_material[i] = (ch._material[i])->clone();
				}
			}
			for(int i =0; i < FLOOR_MATE; i++)
			{
				if(ch._floor[i] == NULL)
					this->_floor[i] = NULL;
				else
				{
					delete _material[i];
					this->_floor[i] = (ch._floor[i])->clone();
				}
			}		
	}
	return *this;
}

Character:: ~Character()
{
	for(int i = 0; i <4; i++)
	{
		if(_material[i])
			delete _material[i];
	}
	for(int i = 0; i< FLOOR_MATE; i++)
	{
		if(_floor[i])
			delete _floor[i];
		else
			return;
	}
}
 std::string const& Character:: getName() const 
 {
	return _name;	
 }
 void Character:: equip(AMateria* m) 
 {
	for(int i = 0; i < 4; i++)
	{
		if(!_material[i])
		{
			_material[i] = m;
			std::cout <<  _name <<" euqip" << m->getType() << std::endl;
			return;
		}
	}
	std::cout << _name << " has 4 material" <<std::endl;
 }
 void Character:: unequip(int idx) 
 {
	if(!(0 <= idx && idx <= 3))
	{
		std::cout << "Please input material index=(0~3)" <<std::endl;
		return;	
	}
	_material[idx] = NULL;
 }
 void Character:: use(int idx, ICharacter& target) 
 {
	if(!(0 <= idx && idx <= 3))
	{
		std::cout <<  "Please input material index=(0~3)" <<std::endl;
		return;	
	}
	_material[idx]->use(target);
 }
