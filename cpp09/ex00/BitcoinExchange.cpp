/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:51:56 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 10:52:25 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &src ) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &rhs ) {
	(void)rhs;
	return *this;
}

size_t	BitcoinExchange::getDbSize( void ) const {
	return (this->_db.size());
}

void	BitcoinExchange::initDataFile( const char *database ) {
	std::ifstream datafile;

	datafile.open(database, std::ifstream::in);
	if (!datafile.is_open())
		throw FileNotOpenException();
	formDatabase(datafile);
	datafile.close();
}

void	BitcoinExchange::formDatabase( std::ifstream &datafile ) {
	std::string left;
	std::string right;

	std::getline(datafile, left);
	if (left.compare("date,exchange_rate") != 0)
	{
		datafile.close();
		throw FirstLineException();
	}
	while (datafile.good())
	{
		//sstream instead comme dans le main? Pour la virgule
		std::getline(datafile, left, ',');
		std::getline(datafile, right);
		left = my_trim(left);
		right = my_trim(right);
		if (isValidDate(left) == 0)
			std::cout << "Empty date" << std::endl;
		else if (isValidValue(right) == 0)
			std::cout << "Empty value" << std::endl;
		else
			this->_db.insert(std::pair<std::string, double>(left, std::atof(right.c_str())));
	}
}

std::string const &BitcoinExchange::getDate(std::string const &date) const {
	std::map<std::string, double>::const_iterator it;
	
	it = this->_db.find(date);
	if (it != this->_db.end())
		return (it->first);
	for (it = this->_db.begin(); it != this->_db.end(); it++)
	{
		int comp = it->first.compare(date);
		if (comp > 0)
		{
			it--;
			return (it->first);
		}
	}
	return (this->_db.rbegin()->first);
}

double	BitcoinExchange::getValue(std::string const &date) const {
	std::map<std::string, double>::const_iterator it;
	
	it = this->_db.find(date);
	if (it != this->_db.end())
		return (it->second);
	for (it = this->_db.begin(); it != this->_db.end(); it++)
	{
		int comp = it->first.compare(date);
		if (comp > 0)
		{
			it--;
			return (it->second);
		}
	}
	return (this->_db.rbegin()->second);
}