/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:49:16 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/16 17:46:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trapster");

	std::cout << "\n--- Tests d'attaque ---\n";
	clap1.attack("Trapster");
	clap2.attack("Clappy");

	std::cout << "\n--- Tests de dégâts ---\n";
	clap2.takeDamage(5);
	clap1.takeDamage(12);

	std::cout << "\n--- Tests de réparation ---\n";
	clap1.beRepaired(8);
	clap2.beRepaired(3);

	std::cout << "\n--- Tests énergie ---\n";
	for (int i = 0; i < 11; i++)
		clap2.attack("Clappy");

	clap2.beRepaired(5);

	std::cout << "\n--- Fin des tests ---\n";

	return 0;
}
