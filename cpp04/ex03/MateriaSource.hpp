#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[4];
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &src );
		~MateriaSource();

		MateriaSource	&operator=( MateriaSource const &rhs );

		AMateria	*getInventory( int i ) const;

		void 		learnMateria( AMateria *mat );
		AMateria*	createMateria( std::string const &type );
};

#endif