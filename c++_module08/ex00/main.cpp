/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:38:55 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/06 13:46:26 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(42);

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 999);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

/*
créer une fonction template capable de chercher un entier
dans n’importe quel conteneur (vector, list, deque…) contenant des int.

easyfind :
- Doit retourner un itérateur vers la première occurrence de value
- Si la valeur existe pas lances une exception.
*/
