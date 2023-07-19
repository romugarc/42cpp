#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	private:
		std::string	&_Name;
		int			_Hit_Points;
		int			_Energy_Points;
		int			_Attack_Damage;
	public:
		ScavTrap( std::string &name );
		~ScavTrap( void );
};

#endif