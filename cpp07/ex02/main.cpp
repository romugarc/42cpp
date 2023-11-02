#include <iostream>
#include "Array.hpp"
# include <cstdlib>
# include <time.h>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    std::cout << "---------Tests sujet--------" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (test[i] != numbers[i])
            {
             std::cerr << "didn't save the same value!!" << std::endl;
             return 1;
            }
        }
        if (&test == &numbers)
        {
            std::cerr << "Pointers are the same!!" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Mirror copy values OK" << std::endl;
    std::cout << "Pointer addresses (should be different): " << &mirror << " " << &numbers << std::endl;
    std::cout << "Catching OOB exceptions: " << std::endl;
    try 
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    std::cout << "---------Test const--------" << std::endl;
    {
        const Array<int> c = numbers;
        std::cout << c[0] << " " << numbers[0] << std::endl;
    }

    std::cout << "---------Test empty--------" << std::endl;
    {
        Array<int> empty;
        std::cout << " size: " << empty.size() << std::endl;
    }

    delete [] mirror;
    return 0;
}