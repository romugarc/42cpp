#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>

class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weap;
	public:
		HumanA(std::string name, Weapon &weap);
		~HumanA();

		std::string getName() const;

		void	attack (void) const;
};

#endif