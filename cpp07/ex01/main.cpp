/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:08:13 by rgarcia           #+#    #+#             */
/*   Updated: 2023/10/17 12:08:14 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	plus(int &a) {
	a += 1;
}

void	display(char const * &a) {
	std::cout << a << std::endl;
}

int	main( void )
{
	const char	*chaussettes[4] = {"blanche", "noire", "pois verts", "rayures jaunes"};
	int	cho[7] = {7, 7, 7, 7, 7, 7, 7};

	::iter(cho, 7, plus);
	::iter(chaussettes, 4, display);
	for (int i = 0; i < 7; i++)
		std::cout << cho[i] << std::endl;
	return 0;
}