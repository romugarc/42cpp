#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		Dog( Dog const &src );
		~Dog( void );

		Dog	&operator=( Dog const &rhs );

		virtual void	makeSound() const;
		Brain	*getBrain( void ) const;
};

#endif