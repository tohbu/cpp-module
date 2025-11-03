#include "Brain.hpp"

Brain ::Brain(): _ideas()
{
	std::cout << "Brain default constructor called" <<std::endl;
}

Brain ::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" <<std::endl;
	for(int i = 0; i<100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain:: ~Brain()
{
	std::cout << "Brain destructor called" <<std::endl;	
}
Brain& Brain::operator=(const Brain& b)
{
	if(this != &b)
	{
		for(int i = 0; i < 100; i++)
			this->_ideas[i]=b._ideas[i];
	}
	return *this;
}