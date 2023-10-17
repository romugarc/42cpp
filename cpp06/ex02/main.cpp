/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:31:36 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 11:31:38 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
