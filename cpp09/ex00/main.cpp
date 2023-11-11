/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:53:17 by rgarcia           #+#    #+#             */
/*   Updated: 2023/11/09 10:53:40 by rgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	error_handler(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}
	if (argv[1] == NULL)
	{
		std::cout << "No file argument" << std::endl;
		return 1;	
	}
	if (argv[1][0] == '\0')
	{
		std::cout << "No file argument" << std::endl;
		return 1;
	}
	return 0;
}

std::string	my_trim(std::string s)
{
	if (!s.empty())
	{
		size_t start = s.find_first_not_of(' ');
		std::string subs = s.substr(start);
		size_t end = s.find_last_not_of(' ');

		subs = s.substr(start, (end + 1 - start));
		return (subs);
	}
	return (s);
}

void	checkFile(std::ifstream &newfile, std::string &line)
{
	if (!newfile.is_open())
		throw BitcoinExchange::FileNotOpenException();
	std::getline(newfile, line);
	if (line.compare("date | value") != 0)
		throw BitcoinExchange::FirstLineException();
}

int	isValidValue(std::string value)
{
	double	val;
	int	points = 0;

	if (value.empty())
		return 0;
	for (size_t k = 0; k < value.size(); k++)
	{
		if (!std::isdigit(value[k]) && value[k] != '.')
			return -4;
		if (value[k] == '.')
			points++;
	}
	if (points > 1)
		return -3;
	val = std::atof(value.c_str());
	if (val > 1000.0)
		return -2;
	if (val < 0.0)
		return -1;
	return 1;
}

int	isValidDay(int day, int month, int year) {
	if (year % 4 == 0 && month == 2)
	{
		if (day > 29)
			return 0;
	}
	else if (month == 2)
	{
		if (day > 28)
			return 0;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return 0;
	}
	else
	{
		if (day > 31)
			return 0;
	}
	return 1;
}

int	countDigits(std::string const &s)
{
	int	count = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (std::isdigit(s[i]))
			count++;
	}
	return (count);
}

int	isValidDate(std::string left) {
	double val;
	size_t i = 0;
	size_t j = 0;
	int day;
	int month;
	int year;

	if (!left.empty())
	{
		i = left.find_first_of('-');
		if (i == std::string::npos)
			return -1;
	}
	else
		return -2;
	for (size_t k = 0; k < i; k++)
	{
		if (!std::isdigit(left[k]))
			return -3;
	}
	std::string subs = left.substr(0, i);
	if (countDigits(subs) != 4)
		return -13;
	val = std::atof(subs.c_str());
	if (val > 9999 || val < 2009)
		return -4;
	year = std::atoi(subs.c_str());
	subs = left.substr(i + 1, left.size());
	if (!subs.empty())
	{
		j = subs.find_first_of('-');
		if (j == std::string::npos)
			return -5;
	}
	else
		return -6;
	for (size_t k = 0; k < j; k++)
	{
		if (!std::isdigit(subs[k]))
			return -7;
	}
	subs = left.substr(i + 1, j);
	if (countDigits(subs) != 2)
		return -14;
	val = std::atof(subs.c_str());
	if (val > 12 || val < 1)
		return -8;
	month = std::atoi(subs.c_str());
	subs = left.substr(i + j + 2, left.size());
	if (subs.empty())
		return -9;
	for (size_t k = 0; k < subs.size(); k++)
	{
		if (!std::isdigit(subs[k]))
			return -10;
	}
	if (countDigits(subs) != 2)
		return -15;
	val = std::atof(subs.c_str());
	if (val > 31 || val < 1)
		return -11;
	day = std::atoi(subs.c_str());
	if (isValidDay(day, month, year) == 0)
		return -12;
	return 1;
}

int	main(int argc, char **argv)
{
	std::ifstream newfile;
	std::string line;
	std::string left;
	std::string right;
	BitcoinExchange exchange;

	if (error_handler(argc, argv) == 1)
		return 0;

	newfile.open(argv[1], std::ifstream::in);
	try
	{
		checkFile(newfile, line);
	}
	catch (const std::exception &e)
	{
		newfile.close();
		std::cout << e.what() << '\n';
		return 0;
	}

	try
	{
		exchange.initDataFile("data.csv");
		if (exchange.getDbSize() == 0)
		{	
			std::cout << "Database is empty" << std::endl;
			return 0;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}

	while (newfile.good())
	{
		std::getline(newfile, line);
		if (line.find ('|') == std::string::npos)
			std::cout << "Error: missing '|' in format" << std::endl;
		else
		{
			std::stringstream line_stream(line);
			std::getline(line_stream, left, '|');
			std::getline(line_stream, right);
			left = my_trim(left);
			right = my_trim(right);
			if (isValidDate(left) <= 0)
				std::cout << "Error: bad input => " << left << std::endl;
			else if (isValidValue(right) <= 0)
				std::cout << "Error: bad value => " << right << std::endl;
			else
				std::cout << exchange.getDate(left) << " => " << std::atof(right.c_str()) << " = " << exchange.getValue(left) * std::atof(right.c_str()) << std::endl;
		}
	}

	newfile.close();
	
	return 0;
}