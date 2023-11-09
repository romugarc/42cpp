/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:56:04 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 06:56:22 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {
}

RPN::RPN( RPN const &src ) {
	*this = src;
}

RPN::~RPN() {
}

RPN	&RPN::operator=( RPN const & rhs ) {
	(void)rhs;
	return *this;
}

double	RPN::getResult() {
	return (this->_list.back());
}
 
double	RPN::getSize() {
	return (this->_list.size());
}

void	RPN::pushToList(char c) {
	this->_list.push_back(c - '0');
}

void	RPN::calculate(char operand)
{
	double	result;
	double	first;
	double	second;

	if (operand == '+')
	{
		first = this->_list.back();
		this->_list.pop_back();
		second = this->_list.back();
		this->_list.pop_back();
		result = second + first;
		this->_list.push_back(result);
	}
	if (operand == '-')
	{
		first = this->_list.back();
		this->_list.pop_back();
		second = this->_list.back();
		this->_list.pop_back();
		result = second - first;
		this->_list.push_back(result);
	}
	if (operand == '*')
	{
		first = this->_list.back();
		this->_list.pop_back();
		second = this->_list.back();
		this->_list.pop_back();
		result = second * first;
		this->_list.push_back(result);
	}
	if (operand == '/')
	{
		first = this->_list.back();
		this->_list.pop_back();
		second = this->_list.back();
		this->_list.pop_back();
		if (first != 0)
			result = second / first;
		else
			throw DivisionByZeroException();
		this->_list.push_back(result);
	}
}