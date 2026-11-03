/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:20:51 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 19:39:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) :
	type("")
{
}

Weapon::Weapon(std::string type) :
	type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string&
Weapon::getType() const
{
	return this->type;
}

void
Weapon::setType(const std::string& type)
{
	this->type = type;
}
