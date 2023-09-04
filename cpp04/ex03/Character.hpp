#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
		long		*_floor;
		long		_floorsize;
	
	public:
		Character( void );
		Character( Character const &src );
		Character( std::string name );
		~Character();

		Character	&operator=( Character const & rhs );

		std::string const	&getName( void ) const;
		AMateria			*getInventory( int i ) const;
		int					getFloorsize( void ) const;

		virtual void equip( AMateria *m );
		virtual void unequip( int idx );
		virtual void use( int idx, ICharacter &target );
};

#endif