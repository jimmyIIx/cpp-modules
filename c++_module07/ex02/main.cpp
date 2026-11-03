/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:02:50 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/01 18:27:34 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main(void)
{
	// Création d'un tableau vide
	Array<int> emptyArray;
	std::cout << "emptyArray size: " << emptyArray.size() << std::endl;

	// Création d'un tableau de 5 éléments
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	std::cout << "numbers: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	// Test de la copie
	Array<int> copy = numbers;
	std::cout << "copy: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	// Test de l'opérateur d'affectation
	Array<int> assign;
	assign = numbers;
	std::cout << "assign: ";
	for (unsigned int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << " ";
	std::cout << std::endl;

	// Test des exceptions
	try
	{
		numbers[10] = 100; // hors limites
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: index out of bounds" << std::endl;
	}

	try
	{
		int value = numbers[10]; // hors limites
		(void)value;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: index out of bounds" << std::endl;
	}

	return (0);
}
