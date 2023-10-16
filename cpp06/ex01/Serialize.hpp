#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serialize
{
	public:
		Serialize( void );
		Serialize( Serialize const &src );
		~Serialize();

		Serialize &operator=( Serialize const &rhs );

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif