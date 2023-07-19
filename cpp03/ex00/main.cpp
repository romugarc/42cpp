#include "ClapTrap.hpp"

int	main(void)
{
	std::string	name;

	name = "NAME";

	ClapTrap	test(name);

	test.attack("bigboi");
	test.takeDamage(1);
	test.beRepaired(1);
	test.takeDamage(-1);
	test.takeDamage(10);
	test.takeDamage(10);
	test.takeDamage(-1);
	test.beRepaired(10);
	test.beRepaired(10);
	test.beRepaired(-1);
	test.attack("sauce");
	return 0;
}