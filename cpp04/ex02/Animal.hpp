#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		AAnimal( AAnimal const &src );
		virtual ~AAnimal( void );

		AAnimal	&operator=( AAnimal const &rhs );

		std::string	getType( void ) const;

		virtual void	makeSound() const = 0;
};

#endif