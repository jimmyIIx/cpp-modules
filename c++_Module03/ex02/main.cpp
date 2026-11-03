/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:49:08 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/22 16:27:18 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
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

	std::cout << "\n=== Création de FragTrap ===" << std::endl;
	FragTrap frag("FR4G-TP");
	frag.attack("Robot");
	frag.takeDamage(15);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "\n=== Test constructeur de copie et opérateur d'affectation ===" << std::endl;
	FragTrap fragCopy(frag); // constructeur de copie
	FragTrap fragAssign;
	fragAssign = frag;       // opérateur d'affectation
	fragCopy.highFivesGuys();
	fragAssign.highFivesGuys();

	std::cout << "\n=== Fin du programme ===" << std::endl;
	return 0;
}
