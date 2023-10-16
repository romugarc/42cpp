#include "Serialize.hpp"

Serialize::Serialize( void ) {
}

Serialize::Serialize( Serialize const &src ) {
	*this = src;
}

Serialize	&Serialize::operator=( Serialize const &rhs ) {
	(void)rhs;
	return *this;
}

Serialize::~Serialize() {
}

uintptr_t Serialize::serialize(Data* ptr) {
    uintptr_t result = reinterpret_cast<uintptr_t>(ptr);

    return ( result );
}

Data* Serialize::deserialize(uintptr_t raw) {
    Data *data = reinterpret_cast<Data *>(raw);
    
    return ( data );
}