/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:54:31 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 06:55:02 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int	numberOfOperands(char *s)
{
	int	ret = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isOperand(s[i]))
			ret = ret + 1;
	}
	return (ret);
}

int	numberOfDigits(char *s)
{
	int	ret = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (std::isdigit(s[i]))
			ret = ret + 1;
	}
	return (ret);
}

int	error_handler(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: argument is invalid" << std::endl;
		return 1;
	}
	if (argv[1][0] == '\0')
	{
		std::cout << "Error: only digits and operands allowed" << std::endl;
		return 1;
	}
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		while (argv[1][i] == ' ')
			i++;
		if (!(std::isdigit(argv[1][i])) && !(isOperand(argv[1][i])))
		{
			std::cout << "Error: only digits and operands allowed" << std::endl;
			return 1;
		}
		if (numberOfDigits(argv[1]) - numberOfOperands(argv[1]) != 1)
		{
			std::cout << "Error: invalid format" << std::endl;
			return 1;
		}
	}
	return 0;
}

int	main (int argc, char **argv)
{
	RPN rpn;

	if (error_handler(argc, argv) == 1)
		return 0;
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		while (argv[1][i] == ' ')
			i++;
		if (std::isdigit(argv[1][i]))
			rpn.pushToList(argv[1][i]);
		if (isOperand(argv[1][i]) == 1)
		{
			if (rpn.getSize() < 2)
			{
				std::cout << "Error: operand is misplaced" << std::endl;
				return 0;
			}
			else
			{
				try
				{
					rpn.calculate(argv[1][i]);
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
					return 0;
				}
			}
		}
	}
	std::cout << "Result: " << rpn.getResult() << std::endl;
	return 0;
}