#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongCat const &src );
		~WrongCat( void );

		WrongCat	&operator=( WrongCat const &rhs );

		virtual void	makeSound() const;
};

#endif