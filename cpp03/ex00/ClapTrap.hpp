#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap 
{
	private:
		std::string		_Name;
		unsigned int	_Hit_Points;
		unsigned int	_Energy_Points;
		unsigned int	_Attack_Damage;
	public:
		ClapTrap( void );
		ClapTrap( std::string &name );
		ClapTrap( ClapTrap const &src );
		~ClapTrap( void );

		ClapTrap	&operator=( ClapTrap const &rhs );

		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

		std::string 	getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		void	setName(std::string name);
		void	setHitPoints(unsigned int hp);
		void	setEnergyPoints(unsigned int ep);
		void	setAttackDamage(unsigned int ad);
};

#endif