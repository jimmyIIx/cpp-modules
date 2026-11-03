/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:21:32 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 19:39:48 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// constructeur default
HumanA::HumanA(void) :
	name(""),
	arme(NULL)
{
}

// constructeur
HumanA::HumanA(std::string name, Weapon& arme) :
	name(name),
	arme(&arme)
{
}

// destructeur
HumanA::~HumanA(void)
{
}

void
HumanA::attack(void)
{
	if (this->arme)
	{
		std::cout << this->name << " attacks with their "
			<< this->arme->getType() << std::endl;
	}
}
