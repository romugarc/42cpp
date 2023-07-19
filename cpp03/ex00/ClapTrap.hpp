#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap 
{
	private:
		std::string	&_Name;
		int			_Hit_Points;
		int			_Energy_Points;
		int			_Attack_Damage;
	public:
		ClapTrap( std::string &name );
		ClapTrap( ClapTrap &src );
		~ClapTrap( void );

		ClapTrap	&operator=( ClapTrap const &rhs );

		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

#endif