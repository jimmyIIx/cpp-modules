/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:49:12 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/22 16:13:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "=== Création de ClapTrap ===" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.attack("Bandit");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== Création de ScavTrap ===" << std::endl;
	ScavTrap scav("SC4V-TP");
	scav.attack("Badass");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n=== Test constructeur de copie et opérateur d'affectation ===" << std::endl;
	ScavTrap scavCopy(scav); // constructeur de copie
	scavCopy.guardGate();

	ScavTrap scavAssign;
	scavAssign = scav;        // opérateur d'affectation
	scavAssign.attack("Robot");

	std::cout << "\n=== Fin du programme ===" << std::endl;
	return 0;
}
