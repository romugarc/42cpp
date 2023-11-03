/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:34:12 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/27 15:34:14 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	error_handler(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		if (argv[1][i] > 127)
		{
			std::cout << "Character not printable" << std::endl;
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (error_handler(argc, argv) == 1)
		return (1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
