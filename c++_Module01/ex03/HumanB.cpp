/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:21:57 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 19:39:54 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// constructeur default
HumanB::HumanB(void) :
	name("")
{
}

// constructeur
HumanB::HumanB(std::string name) :
	name(name)
{
}

// destructeur
HumanB::~HumanB(void)
{
}

void
HumanB::attack(void)
{
	if (this->arme)
	{
		std::cout << this->name << " attacks with their "
			<< this->arme->getType() << std::endl;
	}
}

void
HumanB::setWeapon(Weapon& arme)
{
	this->arme = &arme;
}
