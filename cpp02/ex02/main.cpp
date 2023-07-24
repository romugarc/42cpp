/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:27:45 by rgarcia           #+#    #+#             */
/*   Updated: 2023/07/24 08:27:47 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	//Tests supplémentaires
    {
    std::cout << " Tests arithm :" << std::endl;
    std::cout << "----------------------------" << std::endl;

    Fixed a;
    Fixed const b(Fixed(40) + Fixed(0.42f) + Fixed(2));
    std::cout << "b = 40 + 0.42 + 2 = " << b << std::endl;

    std::cout << "Test : b - b" << std::endl;
    Fixed const c(Fixed(b) - b);
    std::cout << c << std::endl << std::endl;

    std::cout << "Test : b * 2" << std::endl;
    Fixed const d(Fixed(b) * 2);
    std::cout << d << std::endl << std::endl;

    std::cout << "Test : b / 10" << std::endl;
    Fixed const e(Fixed(b) / 10);
    std::cout << e << std::endl;
	std::cout << "Test : f = b * 10 - 2" << std::endl;
    Fixed f((Fixed(b) * Fixed(10) - Fixed(2)));
    std::cout << "f = " << f << std::endl;

    f = f / Fixed(10) + Fixed(2);
    std::cout << "Test : f = f / 10 + 2" << std::endl;
    std::cout << " f = " << f << std::endl;

    std::cout << " Tests comparison :" << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "B = " << b << std::endl;

    std::cout << "Test : b == b" << std::endl;
    std::cout << (b == b) << std::endl;

    std::cout << "Test : b != b" << std::endl;
    std::cout << (b != b) << std::endl;

    std::cout << "Test : 42 <= b" << std::endl;
    std::cout << (Fixed(42) <= b) << std::endl;

    std::cout << "Test : 42 >= b" << std::endl;
    std::cout << (Fixed(42) >= b) << std::endl;

    std::cout << "Test : b < 42" << std::endl;
    std::cout << (b < Fixed(42)) << std::endl;

    std::cout << "Test : b > 42" << std::endl;
    std::cout << (b > Fixed(42)) << std::endl;

    std::cout << " Tests increment & decrement" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    Fixed g;
    a = Fixed(21.21f);
    std::cout << "a = " << a << std::endl;

    std::cout << "Test : g = ++a" << std::endl;
    g = ++a;
    std::cout << "a = "<< a << std::endl;

    std::cout << "Test : g = a++" << std::endl;
    g = a++;
    std::cout << "g = "<< g << std::endl;
    std::cout << "a = "<< a << std::endl;

    std::cout << "a = " << a << std::endl;

    std::cout << "Test : g = --a" << std::endl;
    g = --a;
    std::cout << "g = "<< g << std::endl;
    std::cout << "a = "<< a << std::endl;

    std::cout << "Test : g = a--" << std::endl;
    g = a--;
    std::cout << "g = "<< g << std::endl;
    std::cout << "a = "<< a << std::endl;

    std::cout << " Test min() max() functions:" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    Fixed const a_c(a);
    Fixed const g_c(g);
    a = Fixed(21.21f);

    std::cout << "a = " << a << std::endl;
    std::cout << "g = " << g << std::endl << std::endl;
    std::cout << "(constant a) a_c = " << a_c << std::endl;
    std::cout << "(constant g) g_c = " << g_c << std::endl;

    std::cout << "a.min(a, g) = " << a.min(a, g) << std::endl;
    std::cout << "a.min(a_c,g_c) = " << a.min(a_c,g_c) << std::endl;

    std::cout << "a.max(a, g) = " << a.max(a, g) << std::endl;
    std::cout << "a.max(a_c,g_c) = " << a.max(a_c,g_c) << std::endl;
    }
	return 0;
}
