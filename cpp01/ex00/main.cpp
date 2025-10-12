#include "Zombie.hpp"
// #include <string>

int main()
{
	Zombie a("a");
	Zombie b("b");
	Zombie* c = newZombie("c"); 

	a.announce();
	b.announce();
	c->announce();
	randomChump("d");
	delete c;
	return 0;
}
