#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer( void );
		Serializer( Serializer const &src );
		~Serializer();

		Serializer &operator=( Serializer const &rhs );

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif