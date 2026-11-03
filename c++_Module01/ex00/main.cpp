/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:29:40 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/25 16:35:20 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*
newZombie(std::string name);

void
randomChump(std::string name);

int	main(void)
{
	Zombie *bob1 = newZombie("bob1");
	bob1->announce();
	Zombie *bob2 = newZombie("bob2");
	bob2->announce();
	Zombie *bob3 = newZombie("bob3");
	bob3->announce();


	randomChump("Eric1");
	randomChump("Eric2");
	randomChump("Eric3");

	delete bob1;
	delete bob2;
	delete bob3;

	return 0;
}
