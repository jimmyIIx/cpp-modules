/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:08:02 by nippolit          #+#    #+#             */
/*   Updated: 2026/03/07 16:26:15 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <cstdlib>


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::string expression = argv[1];
	RPN rpn;

	try
	{
		int result = rpn.evaluate(expression);
		std::cout << result << std::endl;
	}
	catch (const std::exception&)
	{
		return (1);
}

	return (0);
}


/*
calcule polonais
exemple 5 3 +
On met 5 → pile : [5]
On met 3 → pile : [5,3]
On voit + → prend 5 et 3 → 5+3=8 → remet dans pile : [8]

teste :
"3 4 +"
7

"9 2 -"
7

"3 5 *"
15

"8 4 /"
2

"5 1 2 + 4 * + 3 -"
14

"8 9 * 9 - 9 - 9 - 4 - 1 +"
42
*/
