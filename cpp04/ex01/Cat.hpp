#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( Cat const &src );
		~Cat( void );

		Cat	&operator=( Cat const &rhs );

		virtual void	makeSound() const;
};

#endif