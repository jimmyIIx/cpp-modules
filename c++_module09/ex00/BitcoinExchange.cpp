/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:00:15 by nippolit          #+#    #+#             */
/*   Updated: 2026/03/07 15:58:28 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_rates = other._rates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());//ouverture fichier

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())//ignore line vide
			continue;

		size_t comma = line.find(',');//cherche la virgule
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);//recup date avant virgule
		std::string value = line.substr(comma + 1);//recup valeur apres virgule

		float rate = std::strtof(value.c_str(), NULL);//transforme valeur string en float

		_rates[date] = rate;
	}
}

void	BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t sep = line.find('|');//cherche sep
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);//recup date avant sep
		std::string valueStr = line.substr(sep + 1);//recup va apres sep
		// enleve les espaces de partout
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date))//verfi date
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (!isValidNumber(valueStr))//verif valeur
		{
			float value = std::strtof(valueStr.c_str(), NULL);
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float value = stringToFloat(valueStr);
		std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);

		if (it == _rates.end() || it->first > date)
		{
			if (it == _rates.begin())
			{
				std::cerr << "Error: no available rate for date." << std::endl;
				continue;
			}
			--it;
		}

		float result = value * it->second;

		std::cout << date << " => " << value << " = "
					<< std::fixed << std::setprecision(2)
					<< result << std::endl;
	}
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;

	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else
		{
			if (!isdigit(date[i]))
				return false;
		}
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// bissextile
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

bool	BitcoinExchange::isValidNumber(const std::string& value) const
{
	if (value.empty())
		return false;

	int Count = 0;

	for (size_t i = 0; i < value.length(); ++i)
	{
		char c = value[i];

		if (c == '.')
		{
			Count++;
			if (Count > 1) // pas plus d’un point
 				return false;
		}
		else if (!isdigit(c))
		{
			return false;
		}
	}

	// Convertir float
	float num = std::strtof(value.c_str(), NULL);

	if (num < 0.0f)
		return false;
	if (num > 1000.0f)
		return false;

	return true;
}

float	BitcoinExchange::stringToFloat(const std::string& s) const
{
	return std::strtof(s.c_str(), NULL);
}
