#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	_nb;
		static int	const	_bits;
	public:
		Fixed( void );
		Fixed( Fixed const &f );
		~Fixed( void );

		Fixed 	&operator=( Fixed const &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif