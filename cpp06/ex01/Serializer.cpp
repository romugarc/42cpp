#include "Serializer.hpp"

Serializer::Serializer( void ) {
}

Serializer::Serializer( Serializer const &src ) {
	*this = src;
}

Serializer	&Serializer::operator=( Serializer const &rhs ) {
	(void)rhs;
	return *this;
}

Serializer::~Serializer() {
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t result = reinterpret_cast<uintptr_t>(ptr);

    return ( result );
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data *data = reinterpret_cast<Data *>(raw);
    
    return ( data );
}