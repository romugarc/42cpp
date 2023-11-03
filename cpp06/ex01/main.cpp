/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:30:49 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 11:30:51 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main (void)
{
    {
        Data dat;
        Data *ptr;
        uintptr_t num;
    
        std::cout << "-----------data values----------" << std::endl;
        std::cout << dat.getReal() << std::endl;
        std::cout << dat.getNum() << std::endl;
        std::cout << "-----------data values after serialize----------" << std::endl;
        num = Serializer::serialize(&dat);
        std::cout << dat.getReal() << std::endl;
        std::cout << dat.getNum() << std::endl;
        std::cout << "-----------data and ptr values after deserialize----------" << std::endl;
        ptr = Serializer::deserialize(num);
        std::cout << dat.getReal() << std::endl;
        std::cout << dat.getNum() << std::endl;
        std::cout << ptr->getReal() << std::endl;
        std::cout << ptr->getNum() << std::endl;
        std::cout << &dat << " " << ptr << std::endl;
    }   
    return 0;
}
