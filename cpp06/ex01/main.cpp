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
