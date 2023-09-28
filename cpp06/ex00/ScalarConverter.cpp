/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:10:36 by rgarcia           #+#    #+#             */
/*   Updated: 2023/09/27 13:10:39 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {
	*this = src;
}

ScalarConverter	&ScalarConverter::operator=( ScalarConverter const &rhs ) {
	(void)rhs;
	return *this;
}

int	isChar( const char *ch ) {
	int	i = 0;

	while (ch[i] != '\0' && i < 2)
		i++;
	if (i == 2)
		return (0);
	if (ch[i] != '\0')
		return (0);
	return (1);
}

int isInt( const char *ch ) {
	int i = 0;

	if (ch[0] == '-')
		i++;
	while (isdigit(ch[i]))
		i++;
	if (ch[i] != '\0')
		return (0);
	return (1);
}

int	isDouble( const char *ch ) {
	int i = 0;

	if (ch[0] == '-')
		i++;
	while (isdigit(ch[i]))
		i++;
	if (ch[i] != '.')
		return (0);
	i++;
	while (isdigit(ch[i]))
		i++;
	if (ch[i] != '\0')
		return (0);
	return (1);
}

int	isFloat( const char *ch ) {
	int i = 0;

	if (ch[0] == '-')
		i++;
	while (isdigit(ch[i]))
		i++;
	if (ch[i] != '.')
		return (0);
	i++;
	while (isdigit(ch[i]))
		i++;
	if (ch[i] != 'f')
		return (0);
	if (ch[i + 1] != '\0')
		return (0);
	return (1);
}

int	checkType( const char *ch ) {
	if (isChar(ch))
		return CHAR;
	if (isInt(ch))
		return INT;
	if (isFloat(ch))
		return FLOAT;
	if (isDouble(ch))
		return DOUBLE;
	return (0);
}

int	isNanInf ( std::string ch ) {
	int i = 0;

	if (ch[0] == '-')
		i++;
	if (ch.compare("nan") == 0 || ch.compare("nanf") == 0)
		return (NAN);
	if (ch.compare("inf") == 0 || ch.compare("inff") == 0)
		return (INF);
	return (0);
}

void	displayChar( std::string ch, int type ){
	if (type == NAN || type == INF)
	{
		std::cout << "char: " << "impossible" << std::endl;
	}
}

void	displayResult( std::string ch, int type ) {
	displayChar(ch, type);
	displayInt(ch, type);
	displayFloat(ch, type);
	displayDouble(ch, type);
}

void	ScalarConverter::convert( std::string ch ) {
	int	type = 0;

	type = isNanInf(ch);
	if (type == 0)
		type = checkType(ch.c_str());
	
}

ScalarConverter::~ScalarConverter() {
}