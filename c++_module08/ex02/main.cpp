/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:03:05 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/06 14:16:57 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int	main(void)
{
	MutantStack<int> mstack;

	// Test push et top
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl; // 17

	// Test pop et size
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl; // 1

	// Ajouter plus d’éléments
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Parcours avec itérateurs
	std::cout << "\nIterating through MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	// Parcours inversé
	std::cout << "\nReverse iteration:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << std::endl;

	// Compatibilité avec std::stack
	std::stack<int> s(mstack);

	return (0);
}
