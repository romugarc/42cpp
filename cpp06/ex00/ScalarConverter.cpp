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
	if (isdigit(ch[i]) == 1) //decider si ce sera un int ou un char
		return (0);
	if (ch[i] != '\0')
		return (0);
	return (1);
}

int isInt( const char *ch ) {
	double val = std::atof(ch);
	int i = 0;

	if (ch[0] == '-')
		i++;
	while (isdigit(ch[i]))
		i++;
	if (ch[i] != '\0')
		return (0);
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		return (0);
	
	return (1);
}

int	isFloat( const char *ch ) {
	double val = std::atof(ch);
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
	if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::max())
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
	if (ch.compare("+inf") == 0 || ch.compare("+inff") == 0 || ch.compare("-inf") == 0 || ch.compare("-inff") == 0)
		return (INF);
	return (0);
}

int	isNonDisplayable ( double c ) {
	if ((c >= 0 && c < 32) || c == 127)
		return (1);
	return (0);
}

int	convertToInt( const char *ch ) {
	int result;

	result = std::atoi(ch);
	return (result);
}

float convertToFloat( const char *ch ) {
	float result;
	
	result = (float)std::atof(ch);
	return (result);
}

double	convertToDouble( const char *ch ) {
	double result;
	
	result = std::atof(ch);
	return (result);
}

void	displayChar( const char *ch, int type ) {
	if ((type == CHAR && (ch[0] < ' ' || ch[0] > 126)) || (type > CHAR && isNonDisplayable(convertToDouble(ch)) == 1))
	{
		std::cout << "char: " << "non displayable" << std::endl;
		return;
	}
	if (type == NAN || type == INF || (type > CHAR && (convertToDouble(ch) < 0 || convertToDouble(ch) > 127)))
	{
		std::cout << "char: " << "impossible" << std::endl;
		return;
	}
	switch (type)
	{
		case 0:
			std::cout << "char: " << "impossible" << std::endl;
			break;
		case CHAR:
			std::cout << "char: " << "'" << ch  << "'" << std::endl;
			break;
		case INT: //faire toutes les verifications du INT dans la fonction isInt et s'assurer que si la fonction retourne INT, alors il n'y a pas de doute possible
			std::cout << "char: " << "'" << static_cast<char>(convertToInt(ch))  << "'" << std::endl;
			break;
		case FLOAT:
			std::cout << "char: " << "'" << static_cast<char>(convertToFloat(ch))  << "'" << std::endl;
			break;
		case DOUBLE:
			std::cout << "char: " << "'" << static_cast<char>(convertToDouble(ch))  << "'" << std::endl;
			break;
	}
}

void	displayInt( const char *ch, int type ) {
	if (type == NAN || type == INF)
	{
		std::cout << "int: " << "impossible" << std::endl;
		return;
	}
	switch (type)
	{
		case 0:
			std::cout << "int: " << "impossible" << std::endl;
			break;
		case CHAR:
			std::cout << "int: " << "'" << static_cast<int>(ch[0])  << "'" << std::endl;
			break;
		case INT: //faire toutes les verifications du INT dans la fonction isInt et s'assurer que si la fonction retourne INT, alors il n'y a pas de doute possible
			std::cout << "int: " << "'" << convertToInt(ch) << "'" << std::endl;
			break;
		case FLOAT:
			std::cout << "int: " << "'" << static_cast<int>(convertToFloat(ch))  << "'" << std::endl;
			break;
		case DOUBLE:
			std::cout << "int: " << "'" << static_cast<int>(convertToDouble(ch))  << "'" << std::endl;
			break;
	}
}

void	displayFloat( const char *ch, int type ) {
	if (type == NAN || type == INF)
	{
		std::cout << "float: " << (float)std::atof(ch) << "f" << std::endl;
		return;
	}
	switch (type)
	{
		case 0:
			std::cout << "float: " << "impossible" << std::endl;
			break;
		case CHAR:
			std::cout.precision(9);
			std::cout << "float: " << "'" << static_cast<float>(ch[0])  << "'" << std::endl;
			break;
		case INT: //faire toutes les verifications du INT dans la fonction isInt et s'assurer que si la fonction retourne INT, alors il n'y a pas de doute possible
			std::cout.precision(9);
			std::cout << "float: " << "'" << static_cast<float>(convertToInt(ch)) << "'" << std::endl;
			break;
		case FLOAT:
			std::cout.precision(9);
			std::cout << "float: " << "'" << convertToFloat(ch)  << "'" << std::endl;
			break;
		case DOUBLE:
			std::cout.precision(9);
			std::cout << "float: " << "'" << static_cast<float>(convertToDouble(ch))  << "'" << std::endl;
			break;
	}
}

void	displayDouble( const char *ch, int type ) {
	if (type == NAN || type == INF)
	{
		std::cout << "double: " << std::atof(ch) << std::endl;
		return;
	}
	switch (type)
	{
		case 0:
			std::cout << "double: " << "impossible" << std::endl;
			break;
		case CHAR:
			std::cout.precision(17);
			std::cout << "double: " << "'" << static_cast<double>(ch[0])  << "'" << std::endl;
			break;
		case INT: //faire toutes les verifications du INT dans la fonction isInt et s'assurer que si la fonction retourne INT, alors il n'y a pas de doute possible
			std::cout.precision(17);
			std::cout << "double: " << "'" << static_cast<double>(convertToInt(ch)) << "'" << std::endl;
			break;
		case FLOAT:
			std::cout.precision(17);
			std::cout << "double: " << "'" << static_cast<double>(convertToFloat(ch)) << "'" << std::endl;
			break;
		case DOUBLE:
			std::cout.precision(17);
			std::cout << "double: " << "'" << convertToDouble(ch) << "'" << std::endl;
			break;
	}
}

void	displayResult( const char *ch, int type ) {
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
	std::cout << type << std::endl;
	displayResult(ch.c_str(), type);
}

ScalarConverter::~ScalarConverter() {
}