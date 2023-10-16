#include "Serialize.hpp"
#include "Data.hpp"

int main (void)
{
    Data *dat = new Data;
    Serialize seri;
    uintptr_t num;

    std::cout << dat->getReal() << std::endl;
    std::cout << dat->getNum() << std::endl;
    num = seri.serialize(dat);
    dat = seri.deserialize(num);
    std::cout << dat->getReal() << std::endl;
    std::cout << dat->getNum() << std::endl;
    delete dat;
    return 0;
}