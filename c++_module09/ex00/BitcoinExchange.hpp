/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:00:01 by nippolit          #+#    #+#             */
/*   Updated: 2026/03/07 15:16:11 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange& other);
			BitcoinExchange& operator=(const BitcoinExchange& other);
			~BitcoinExchange();

			void	loadDatabase(const std::string& filename); //lire un fichier transfert dans rates
			void	processInput(const std::string& filename) const;//verif fichier input avec info dans rates

	private:
			std::map<std::string, float> _rates;//tab en forme map pour date et valeur bitcoin

			bool	isValidDate(const std::string& date) const;//verif date
			bool	isValidNumber(const std::string& value) const;//verfi valeur (negatif ou trop grand)
			float	stringToFloat(const std::string& s) const;//transforme nombre en string en float
};
