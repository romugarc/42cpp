#include "Zombie.hpp"

int	main(void)
{
	int	n;

	n = 69;
	Zombie* newz = zombieHorde(n, "HakunaMatata");
	while (n > 0)
	{
		newz[n - 1].announce();
		n--;
	}
	delete [] newz;
	return (0);
}