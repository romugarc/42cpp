#include "Serializer.hpp"
#include "Data.hpp"

int main (void)
{
    Data *dat = new Data;
    Serializer seri;
    uintptr_t num;

    std::cout << dat->getReal() << std::endl;
    std::cout << dat->getNum() << std::endl;
    num = seri.serialize(dat);
    std::cout << dat->getReal() << std::endl;
    std::cout << dat->getNum() << std::endl;
    dat = seri.deserialize(num);
    std::cout << dat->getReal() << std::endl;
    std::cout << dat->getNum() << std::endl;
    delete dat;
    
    return 0;
}