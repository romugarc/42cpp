#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Cat( void );
		Cat( Cat const &src );
		~Cat( void );

		Cat	&operator=( Cat const &rhs );

		virtual void	makeSound() const;
		Brain	*getBrain( void ) const;
};

#endif