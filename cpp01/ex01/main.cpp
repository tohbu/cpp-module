#include "Zombie.hpp"
#define N 5
// #include <string>

int main()
{
	Zombie a("a");
	Zombie b("b");
	Zombie *z = zombieHorde(N, "zombies");

	a.announce();
	b.announce();
	for (int i = 0; i < N; i++)
		z[i].announce();
	delete[] z;
	return 0;
}
