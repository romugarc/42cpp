#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {
	private:
		std::string _type;
	public:
		Ice( void );
		Ice( Ice const &src );
		~Ice();

		Ice	&operator=( Ice const &rhs );

		AMateria	*clone( void ) const;

		virtual void	use( ICharacter &target );
};

#endif