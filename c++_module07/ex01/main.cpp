/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:31:42 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/31 16:36:10 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(T const &elem)
{
	std::cout << elem << std::endl;
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	std::string words[] = {"hello", "world", "template"};

	std::cout << "== int array ==" << std::endl;
	iter(tab, 5, printElement<int>);

	std::cout << "\n== string array ==" << std::endl;
	iter(words, 3, printElement<std::string>);

	// test avec un tableau constant
	const double values[] = {1.1, 2.2, 3.3};
	std::cout << "\n== const double array ==" << std::endl;
	iter(values, 3, printElement<double>);

	return 0;
}
