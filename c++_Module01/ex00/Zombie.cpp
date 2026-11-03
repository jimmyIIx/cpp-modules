/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:41:26 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 19:43:51 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructeur default
Zombie::Zombie(void) :
	name("")
{
}

// constructeur
Zombie::Zombie(std::string name) :
	name(name)
{
}

// destructeur
Zombie::~Zombie(void)
{
	std::cout << this->name << " is delete" << std::endl;
}

void
Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
