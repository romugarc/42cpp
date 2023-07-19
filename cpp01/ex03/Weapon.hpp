#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string arme);
		~Weapon();

		std::string const & getType() const;

		void	setType(std::string type);
};

#endif