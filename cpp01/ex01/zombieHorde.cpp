#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0 || !N)
		return NULL;
	Zombie*	newz = new Zombie[N];

	while (N > 0)
	{
		newz[N - 1].setName(name);
		N--;
	}
	return (newz);
}