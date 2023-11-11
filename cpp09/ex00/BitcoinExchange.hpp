/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:52:30 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 10:53:02 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <stdlib.h>
# include <algorithm>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;
	public:
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &src );
		~BitcoinExchange();

		BitcoinExchange &operator=( BitcoinExchange const &rhs );

		void	formDatabase( std::ifstream &datafile );
		void	initDataFile( const char *database );

		std::string const	&getDate(std::string const &date) const;
		double				getValue(std::string const &date) const;

		size_t	getDbSize( void ) const;

		class	FileNotOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class	FirstLineException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

int	error_handler(int argc, char **argv);
std::string	my_trim(std::string s);
int	isValidDay(int day, int month, int year);
int	isValidDate(std::string left);
int	isValidValue(std::string value);

#endif
