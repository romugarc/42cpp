#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( Cure const &src );
		~Cure();

		Cure	&operator=( Cure const &rhs );

		AMateria	*clone( void ) const;

		virtual void	use( ICharacter &target );
};

#endif