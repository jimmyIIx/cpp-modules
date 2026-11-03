/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:02:09 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/24 18:32:45 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook repertory;
	std::string input;
	while (std::cout << "> " << std::flush
			&& std::getline(std::cin, input) && input != "EXIT")
	{
		if (input == "ADD")
			repertory.add();
		else if (input == "SEARCH")
			repertory.search();
	}
	return (0);
}
