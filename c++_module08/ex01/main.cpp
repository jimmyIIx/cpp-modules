/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:47:48 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/06 14:01:36 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int	main(void)
{
	try
	{
		std::cout << "=== Test simple ===" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // 14

		std::cout << "\n=== Test exception ajout ===" << std::endl;
		try
		{
			sp.addNumber(42); // dépassement
		}
		catch (const std::exception &e)
		{
			std::cout << "Expected exception: " << e.what() << std::endl;
		}

		std::cout << "\n=== Test large Span ===" << std::endl;
		Span big(10000);
		std::vector<int> numbers;
		for (int i = 0; i < 10000; ++i)
			numbers.push_back(rand() % 100000);

		big.addRange(numbers.begin(), numbers.end());

		std::cout << "Shortest Span (large): " << big.shortestSpan() << std::endl;
		std::cout << "Longest Span (large): " << big.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
