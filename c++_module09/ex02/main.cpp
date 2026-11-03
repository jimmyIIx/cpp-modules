/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:17:55 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/13 19:53:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	PmergeMe pm(argv + 1);

	// Avant
	const std::vector<int>& v = pm.getVector();
	std::cout << "Before: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	// Tri Vector
	clock_t start = clock();
	pm.sortVector();
	clock_t end = clock();
	double vectorTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

	// tri Deque
	start = clock();
	pm.sortDeque();
	end = clock();
	double dequeTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

	// Apres
	const std::vector<int>& sorted = pm.getVector();
	std::cout << "After: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	// Time
	std::cout << "Time to process a range of " << sorted.size() << " elements with std::vector : "
				<< static_cast<long>(vectorTime) << " us" << std::endl;

	std::cout << "Time to process a range of " << sorted.size() << " elements with std::deque : "
				<< static_cast<long>(dequeTime) << " us" << std::endl;

	return (0);
}

/*
test :

chill
./ex02 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9

impair
./ex02 10 3 8 1 5
Before: 10 3 8 1 5
After: 1 3 5 8 10

doublon
./ex02 4 2 4 1 2
Before: 4 2 4 1 2
After: 1 2 2 4 4

invalides (-) ou (lettre)
./ex02 3 -5 7
./ex02 3 a 7
Error

3000 element
./ex02 $(shuf -i 1-100000 -n 3000 | tr "\n" " ")
*/
