#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_nb;
		static int	const	_bits;
	public:
		Fixed( void );
		Fixed( Fixed const &f );
		Fixed( int const toconvert );
		Fixed( float const toconvertf );
		~Fixed( void );

		Fixed 	&operator=( Fixed const &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;
};

std::ostream	&operator<<( std::ostream &o, Fixed const &src );

#endif