#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	newz = new Zombie[N];

	while (N > 0)
	{
		newz[N - 1].setName(name);
		N--;
	}
	return (newz);
}