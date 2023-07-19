#include "Zombie.hpp"

int	main(void)
{
	Zombie* newz;

	randomChump("Manu");
	newz = newZombie("JeanLuc");
	newz->announce();
	delete newz;
	return (0);
}