/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:57:10 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 08:57:39 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char	*RPN::DivisionByZeroException::what() const throw() {
	return ("Exception: Division by Zero detected");
}