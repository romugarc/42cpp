#include "Base.hpp"

int main ( void )
{
    Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);

    delete ptr;

    return 0;
}