#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>

class	HumanB
{
	private:
		std::string	_name;
		Weapon		*_weap;
	public:
		HumanB(std::string name);
		~HumanB();

		std::string getName() const;

		void	setWeapon(Weapon &weap);
		void	attack (void) const;
};

#endif
