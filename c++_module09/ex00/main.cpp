/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:59:20 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/07 11:14:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	std::string inputFile = argv[1];

	BitcoinExchange btc;
	btc.loadDatabase("data.csv"); // la base fournie par le sujet
	btc.processInput(inputFile);

	return (0);
}

/*
input = celui du sujet

input-simple = juste

input-erreur =
-5 -> Error: not a positive number.
2011-02-30 -> Error: bad input => 2011-02-30
1001 -> Error: too large a number.
2012-01-12 -> devrait prendre le taux le plus proche inférieur dans la DB

input-data = date manquantes
*/
